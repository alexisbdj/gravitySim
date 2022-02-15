#include <stdlib.h>
#include "Object.h"
#include "ErrorHandling.h"

Object_t *Object_create(Vector3 pos, float radius, Color color)
{
    Object_t *obj = malloc(sizeof(Object_t));

    if (obj == NULL) {
        printError("malloc failed.");
        return NULL;
    }
    obj->pos = pos;
    obj->radius = radius;
    obj->color = color;

    return obj;
}

void Object_destroy(Object_t *obj)
{
    free(obj);
}

void Object_render(Object_t *obj)
{
    DrawSphere(obj->pos, obj->radius, obj->color);
}