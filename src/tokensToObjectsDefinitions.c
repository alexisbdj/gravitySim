#include <stdlib.h>
#include "Utils.h"
#include "ObjectDefinition.h"
#include "ErrorHandling.h"

ObjAttribute_t *getAttribute(const Token_t * tokens, int tokenCount, int *i)
{
    char *name = NULL;
    const Token_t *value = NULL;
    ObjAttribute_t *attr = NULL;
    name = tokens[*i].content;
    (*i)++;
    if ((*i) >= tokenCount) {
        printError("unexpected end of file");
        return NULL;
    }
    if (!(tokens[*i].type & TK_EQUAL)) {
        printError("exected equal");
        return NULL;
    }
    (*i)++;
    if ((*i) >= tokenCount) {
        printError("unexpected end of file");
        return NULL;
    }
    if (!(tokens[*i].type & (TK_NAME | TK_NUM | TK_FLOAT))) {
        printError("expected value");
        return NULL;
    }
    value = &tokens[*i];
    attr = malloc(sizeof(ObjAttribute_t));
    if (!attr)
        return NULL;
    attr->name = name;
    attr->value = value;
    return attr;
}

ObjectDefinition_t *readObjectContent(const Token_t * tokens, int tokenCount, int *i)
{
    ObjectDefinition_t *current = malloc(sizeof(ObjectDefinition_t));

    current->attributes = NULL;
    if (!current) {
        printError("failed to malloc");
        return NULL;
    }
    (*i)++;
    while ((*i) < tokenCount && (tokens[*i].type & TK_EOL)) {
        (*i)++;
    }
    if ((*i) >= tokenCount) {
        free(current);
        printError("unexpected end of file");
        return NULL;
    }
    if (!(tokens[*i].type & TK_BLOCKSTART)) {
        free(current);
        printError("expected block start");
        return NULL;
    }
    (*i)++;

    while (true) {
        while ((*i) < tokenCount && (tokens[*i].type & TK_EOL)) {
            (*i)++;
        }
        if ((*i) >= tokenCount) {
            free(current);
            printError("unexpected end of file");
            return NULL;
        }
        if (tokens[*i].type & TK_BLOCKEND)
            return current;
        else if (tokens[*i].type & TK_NAME) {
            ObjAttribute_t *attr = getAttribute(tokens, tokenCount, i);
            if (!attr) {
                free(current);
                return NULL;
            }
            current->attributes = LinkedList_push(current->attributes, attr);
        }
        else {
            free(current);
            printError("expected attribute name");
            return NULL;
        }
        (*i)++;
    }
}

LinkedList *tokensToObjectsDefinitions(const Token_t * tokens, int tokenCount)
{
    LinkedList *definitions = NULL;
    ObjectDefinition_t *current;
    char *name;
    for (int i = 0; i < tokenCount; i++) {
        current = NULL;
        if (tokens[i].type & TK_AREASTART) {
            i++;    //skip next token to ignore area's name
        }
        else if (tokens[i].type & TK_NAME) {
            name = tokens[i].content;
            current = readObjectContent(tokens, tokenCount, &i);
            if (current == NULL) {
                return NULL;
            }
            current->name = name;
            definitions = LinkedList_push(definitions, current);
            if (definitions == NULL) {
                return NULL;
            }
        }
        else if (!(tokens[i].type & TK_EOL)) {
            printError("got wrong token type");
            return NULL;
        }
    }

    return definitions;
}


void ObjectDefinition_destroy(ObjectDefinition_t *def)
{
    LinkedList_destroy(def->attributes);
    free(def);
}