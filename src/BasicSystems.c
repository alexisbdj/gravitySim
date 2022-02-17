#include "SystemList.h"

int applyVelocity(Object_t * obj, __attribute__((unused)) ObjectList_t *list, float deltaTime)
{
    obj->pos.x += obj->velocity.x * deltaTime;
    obj->pos.y += obj->velocity.y * deltaTime;
    obj->pos.z += obj->velocity.z * deltaTime;

    return 0;
}