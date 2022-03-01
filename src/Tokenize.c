#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "FileParsing.h"
#include "FileReader.h"

static const size_t blockSize = 25;

static Token_t * addToken(Token_t * tokenList, int *count, char * content, TokenFlag type)
{
    if (tokenList == NULL) {
        tokenList = malloc(sizeof(Token_t) * blockSize);
        *count = 0;
    }
    if ((((*count) + 1) % blockSize) == 0) {
        int nblocks = ((*count) + 1) / blockSize + 1;
        tokenList = realloc(tokenList, sizeof(Token_t) * (blockSize * nblocks));
    }
    tokenList[*count].content = content;
    tokenList[*count].type = type;
    (*count)++;
    return tokenList;
}

Token_t * tokenize(Parser_t * parser, FileReader_t * reader, int *count)
{
    Token_t * tokenList = NULL;
    char * current = NULL;
    char c;
    TokenFlag flag = parser->totalValue;

    while ((c = FileReader_getChar(reader)) != '\0') {
        int restart = 0;
        do {
            restart = 0;
            current = addCharToWord(current, c);
            TokenFlag tmpFlag = runValidators(parser, current, flag);
            if (tmpFlag == 0) {
                current[strlen(current) - 1] = 0;
                if (strlen(current) > 0) {
                    noticeProcess;
                    restart = 1;
                    tokenList = addToken(tokenList, count, current, flag);
                }
                else {
                    free(current);
                }
                current = NULL;
                flag = parser->totalValue;
            }
            else {
                flag = tmpFlag;
            }
        } while(restart);
    }
    return tokenList;
}
