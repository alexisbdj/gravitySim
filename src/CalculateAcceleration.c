#include "SystemList.h"
#include "VectorOperations.h"
#include "Utils.h"

int calculateAcceleration(Object_t * obj, __attribute__((unused)) ObjectList_t *list, __attribute__((unused)) float deltaTime)
{
    obj->acceleration = Vector3_division(obj->force, obj->mass);

    return 0;
}