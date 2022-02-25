#ifndef OBJECT_DEFINITION_H_
#define OBJECT_DEFINITION_H_

#include "FileParsing.h"

typedef struct {
    char *name;
    const Token_t *value;
} ObjAttribute_t;

typedef struct {
    char * name;
    ObjAttribute_t *attributes;
} ObjectDefinition_t;

ObjectDefinition_t *tokensToObjectsDefinitions(int *objCount, const Token_t * tokens, int tokenCount);

#endif