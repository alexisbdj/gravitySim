#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "ObjectDefinition.h"
#include "ErrorHandling.h"

static const size_t blockSize = 25;

static ObjectDefinition_t *addObjectDef(ObjectDefinition_t * objList, int *count, ObjectDefinition_t * newObj)
{
    if (objList == NULL) {
        objList = malloc(sizeof(ObjectDefinition_t) * blockSize);
        *count = 0;
    }
    if ((((*count) + 1) % blockSize) == 0) {
        int nblocks = ((*count) + 1) / blockSize + 1;
        objList = realloc(objList, sizeof(ObjectDefinition_t) * (blockSize * nblocks));
    }
    objList[*count] = (*newObj);
    (*count)++;
    return objList;
}


ObjAttribute_t *getAttribute(ObjectDefinition_t *current, const Token_t * tokens, int tokenCount, int *i)
{
    (void)current;
    (void)tokens;
    (void)tokenCount;
    (void)i;
    return NULL;
}

int readObjectContent(ObjectDefinition_t *current, const Token_t * tokens, int tokenCount, int *i)
{
    char *name = NULL;
    const Token_t *value = NULL;
    (*i)++;
    while ((*i) < tokenCount && (tokens[*i].type & TK_EOL)) {
        (*i)++;
    }
    if ((*i) >= tokenCount) {
        printError("unexpected end of file");
        return 1;
    }
    if (!(tokens[*i].type & TK_BLOCKSTART)) {
        printError("expected block start");
        return 1;
    }
    (*i)++;

    while (true) {
        while ((*i) < tokenCount && (tokens[*i].type & TK_EOL)) {
            (*i)++;
        }
        if ((*i) >= tokenCount) {
            printError("unexpected end of file");
            return 1;
        }
        if (tokens[*i].type & TK_BLOCKEND)
            return 0;
        else if (tokens[*i].type & TK_NAME) {
            name = tokens[*i].content;
            (*i)++;
            if (!(tokens[*i].type & TK_EQUAL)) {
                printf("err: %s - %s\n", binaryFlag(tokens[*i].type), tokens[*i].content);
                printError("exected equal");
                return 1;
            }
            (*i)++;
            if (!(tokens[*i].type & (TK_NAME | TK_NUM | TK_FLOAT))) {
                printf("err: %s - %s\n", binaryFlag(tokens[*i].type), tokens[*i].content);
                printError("expected value");
                return 1;
            }
            value = &tokens[*i];
            printf("attr: %s = %s\n", name, value->content);

        }
        else {
            printError("expected attribute name");
            return 1;
        }
        (*i)++;
    }
    return 0;
}

ObjectDefinition_t *tokensToObjectsDefinitions(int *objCount, const Token_t * tokens, int tokenCount)
{
    ObjectDefinition_t *defintions = NULL;
    ObjectDefinition_t current;
    for (int i = 0; i < tokenCount; i++) {
        if (tokens[i].type & TK_AREASTART) {
            i++;    //skip next token to ignore area's name
        }
        else if (tokens[i].type & TK_NAME) {
            printf("readObject: %s\n", tokens[i].content);
            readObjectContent(&current, tokens, tokenCount, &i);
        }
        else if (!(tokens[i].type & TK_EOL)) {
            printError("got wrong token type");
            return NULL;
        }
    }

    return defintions;
}