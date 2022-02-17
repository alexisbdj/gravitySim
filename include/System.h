#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "ObjectList.h"

typedef int (*SystemProcess)(Object_t * obj, ObjectList_t *list, float deltaTime);

typedef struct SystemNode
{
    SystemProcess function;
    struct SystemNode *next;
} System_t;

System_t *System_push(System_t *system, SystemProcess node);

void System_destroy(System_t *system);

int System_processFrame(System_t *system, ObjectList_t *list, float deltaTime);


#endif