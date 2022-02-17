#include <stdlib.h>
#include "ObjectList.h"
#include "ErrorHandling.h"

ObjectList_t *ObjectList_push(ObjectList_t *list, Object_t *element)
{
    ObjectList_t *newNode = malloc(sizeof(ObjectList_t));
    if (newNode == NULL) {
        printError("malloc failed");
    }
    newNode->element = element;
    newNode->next = NULL;
    if (list == NULL) {
        list = newNode;
    }
    else {
        list->next = newNode;
    }
    return list;
}

ObjectList_t *ObjectList_create(ObjectList_t *list, Vector3 pos, float radius, Color color)
{
    Object_t *obj = Object_create(pos, radius, color);
    
    if (obj == NULL) {
        printError("malloc failed");
        return NULL;
    }
    list = ObjectList_push(list, obj);
    if (list == NULL) {
        Object_destroy(obj);
        return NULL;
    }
    return list;
}

void ObjectList_destroy(ObjectList_t *list)
{
    if (list->element)
        Object_destroy(list->element);
    if (list->next) {
        ObjectList_destroy(list->next);
    }
    free(list);
}

void ObjectList_renderAll(ObjectList_t *list)
{
    while (list) {
        Object_render(list->element);
        list = list->next;
    }
}
