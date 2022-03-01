#include "SystemList.h"
#include "VectorOperations.h"
#include "Constants.h"

static float forceValue(Object_t * obj, Object_t * target)
{
    float distance = getDistance(obj->pos, target->pos);
    return (Gconst * (obj->mass * target->mass)/(distance * distance));
}

static Vector3 calcAppliedForce(Object_t * obj, Object_t * target)
{
    Vector3 force = getDirection(obj->pos, target->pos);
    force = Vector3_multiplication(force, forceValue(obj, target));
    return force;
}

int applyGravity(Object_t * obj, ObjectList_t *list, __attribute__((unused)) float deltaTime)
{
    Vector3 g = {0, 0, 0};
    while (list) {
        Object_t * current = list->element;
        if (current != obj) {
            Vector3 force = calcAppliedForce(obj, current);
            if (!Vector3_isNan(force))
                g = Vector3_addition(g, force);
        }
        list = list->next;
    }
    obj->force = Vector3_addition(obj->force, g);
    return 0;
}