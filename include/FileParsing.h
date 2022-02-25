#ifndef FILE_PARSING_H_
#define FILE_PARSING_H_

#include <stdint.h>
#include "stddef.h"
#include "Game.h"
#include "FileReader.h"

typedef uint16_t TokenFlag;
typedef int (*tkValidator)(const char * current);

enum TokenFlagValues {
    TK_EOL = 1,
    TK_NUM = 2,
    TK_FLOAT = 4,
    TK_NAME = 8,
    TK_EQUAL = 16,
    TK_BLOCKSTART = 32,
    TK_BLOCKEND = 64,
    TK_AREASTART = 128,
    TK_AXE = 256,
};

typedef struct {
    TokenFlag type;
    char * content;
} Token_t;

typedef struct {
    TokenFlag value;
    tkValidator validator;
} TokenType;

typedef struct {
    TokenType * types;
    size_t ntypes;
    TokenFlag totalValue;
} Parser_t;

int parseFile(const char * filePath, Game_t * game);

char *addCharToWord(char * current, char c);

TokenFlag runValidators(Parser_t * parser, char * current, TokenFlag flags);

Token_t * tokenize(Parser_t * parser, FileReader_t * reader, int *count);

#endif