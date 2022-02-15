#ifndef OBJECT_H_
#define OBJECT_H_

#include "raylib.h"

typedef struct {
    Vector3 pos;
    float radius;
    Color color;
} Object_t;

Object_t *Object_create(Vector3 pos, float radius, Color color);

void Object_destroy(Object_t *obj);

void Object_render(Object_t *obj);

#endif