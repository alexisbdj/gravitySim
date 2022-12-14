#include <stdlib.h>
#include "System.h"
#include "ErrorHandling.h"

void System_append(System_t *a, System_t *b)
{
    while (a->next)
        a = a->next;
    a->next = b;
}

System_t *System_push(System_t *system, int (*node)(Object_t *obj, ObjectList_t * list, float deltaTime))
{
    System_t *newNode = malloc(sizeof(System_t));

    if (newNode == NULL) {
        printError("malloc failed");
        return NULL;
    }
    newNode->function = node;
    newNode->next = NULL;
    if (system == NULL) {
        system = newNode;
    }
    else {
        System_append(system, newNode);
    }
    return system;
}

void System_destroy(System_t *system)
{
    if (system == NULL)
        return;
    if (system->next) {
        System_destroy(system->next);
    }
    free(system);
}

static int processNode(System_t *system, ObjectList_t *list, float deltaTime)
{
    ObjectList_t *current = list;
    while (current) {
        system->function(current->element, list, deltaTime);
        current = current->next;
    }
    return 0;
}

int System_processFrame(System_t *system, ObjectList_t *list, float deltaTime)
{
    while (system) {
        processNode(system, list, deltaTime);
        system = system->next;
    }
    return 0;
}