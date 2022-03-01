#ifndef OBJECT_LIST_H_
#define OBJECT_LIST_H_

#include "Object.h"

typedef struct ObjectNode {
    Object_t *element;
    struct ObjectNode *next;
} ObjectList_t;

ObjectList_t *ObjectList_push(ObjectList_t *list, Object_t *element);

ObjectList_t *ObjectList_quickCreate(ObjectList_t *list, Vector3 pos, float radius, Color color);

ObjectList_t *ObjectList_create(ObjectList_t *list, Object_t **newObjPtr);

void ObjectList_destroy(ObjectList_t *list);

void ObjectList_renderAll(ObjectList_t *list);

#endif