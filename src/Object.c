#include <stdlib.h>
#include <string.h>
#include "Object.h"
#include "ObjectList.h"
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
    obj->velocity = (Vector3){0, 0, 0};
    obj->force = (Vector3){0, 0, 0};
    obj->acceleration = (Vector3){0, 0, 0};
    obj->mass = 30;
    obj->name = NULL;

    return obj;
}

void Object_destroy(Object_t *obj)
{
    if (obj->name != NULL)
        free(obj->name);
    free(obj);
}

void Object_render(Object_t *obj)
{
    DrawSphere(obj->pos, obj->radius, obj->color);
}