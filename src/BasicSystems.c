#include "SystemList.h"

int applyVelocity(Object_t * obj, __attribute__((unused)) ObjectList_t *list, float deltaTime)
{
    obj->pos.x += obj->velocity.x * deltaTime;
    obj->pos.y += obj->velocity.y * deltaTime;
    obj->pos.z += obj->velocity.z * deltaTime;

    return 0;
}

int resetForce(Object_t * obj, __attribute__((unused)) ObjectList_t *list, __attribute__((unused)) float deltaTime)
{
    obj->force = (Vector3){0, 0, 0};
    return 0;
}

int applyAcceleration(Object_t * obj, __attribute__((unused)) ObjectList_t *list, float deltaTime)
{
    obj->velocity.x += obj->acceleration.x * deltaTime;
    obj->velocity.y += obj->acceleration.y * deltaTime;
    obj->velocity.z += obj->acceleration.z * deltaTime;

    return 0;
}