#ifndef OBJECT_DEFINITION_H_
#define OBJECT_DEFINITION_H_

#include "FileParsing.h"
#include "LinkedList.h"

typedef struct {
    char *name;
    const Token_t *value;
} ObjAttribute_t;

typedef struct {
    char * name;
    LinkedList *attributes;
} ObjectDefinition_t;

LinkedList *tokensToObjectsDefinitions(const Token_t * tokens, int tokenCount);
void ObjectDefinition_destroy(ObjectDefinition_t *def);

#endif