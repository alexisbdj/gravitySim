#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "FileParsing.h"
#include "ErrorHandling.h"
#include "string.h"
#include "LinkedList.h"
#include "ParserValidators.h"
#include "FileReader.h"
#include "Utils.h"
#include "ObjectDefinition.h"

static int registerType(Parser_t * parser, size_t * currentN, TokenFlag flag, tkValidator validator)
{
    if ((*currentN) >= parser->ntypes) {
        printError("can't register more flags");
        return 1;
    }
    parser->types[*currentN].value = flag;
    parser->types[*currentN].validator = validator;
    parser->totalValue += flag;
    (*currentN)++;
    return 0;
}

static int initParser(Parser_t * parser)
{
    parser->ntypes = 9;
    parser->totalValue = 0;
    parser->types = malloc(sizeof(TokenType) * parser->ntypes);
    size_t currentN = 0;
    int errorOccured = 0;

    errorOccured |= registerType(parser, &currentN, TK_EOL, eol_validator);
    errorOccured |= registerType(parser, &currentN, TK_NUM, num_validator);
    errorOccured |= registerType(parser, &currentN, TK_FLOAT, float_validator);
    errorOccured |= registerType(parser, &currentN, TK_NAME, name_validator);
    errorOccured |= registerType(parser, &currentN, TK_EQUAL, equal_validator);
    errorOccured |= registerType(parser, &currentN, TK_BLOCKSTART, blockstart_validator);
    errorOccured |= registerType(parser, &currentN, TK_BLOCKEND, blockend_validator);
    errorOccured |= registerType(parser, &currentN, TK_AREASTART, areastart_validator);
    errorOccured |= registerType(parser, &currentN, TK_AXE, axe_validator);

    if (currentN != parser->ntypes) {
        printError("didn't get expected number of flags");
        errorOccured = 1;
    }

    if (errorOccured) {
        free(parser->types);
        return 1;
    }
    return 0;
}

static void cleanParser(Parser_t * parser)
{
    free(parser->types);
}

static int fparseFile(int fd, Game_t * game, Parser_t * parser)
{
    (void)game;
    FileReader_t *reader = FileReader_create(fd, 255);
    Token_t *tokens = NULL;
    int tokenCount = 0;
    LinkedList *objDefs;
    if (reader == NULL) {
        printError("failed to init reader");
        return 1;
    }
    tokens = tokenize(parser, reader, (void*)&tokenCount);
    objDefs = tokensToObjectsDefinitions(tokens, tokenCount);
    if (objDefs == NULL) {
        return 1;
    }

    LinkedList_foreach(objDefs, (void*)&printObjDef);

    FileReader_destroy(reader);
    return 0;
}

int parseFile(const char * filePath, Game_t * game)
{
    int fd = open(filePath, O_RDONLY);
    Parser_t parser;
    int ret = 0;

    if (fd == -1) {
        printError(strerror(errno));
        return 1;
    }
    if (initParser(&parser) != 0) {
        printError("couldn't initialize parser");
        close(fd);
        return 1;
    }
    ret = fparseFile(fd, game, &parser);
    close(fd);
    cleanParser(&parser);
    return ret;
}