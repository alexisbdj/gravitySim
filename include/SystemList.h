#ifndef SYSTEM_LIST_H_
#define SYSTEM_LIST_H_

#include "System.h"

int applyVelocity(Object_t * obj, ObjectList_t *list, float deltaTime);
int resetForce(Object_t * obj, ObjectList_t *list, float deltaTime);
int calculateAcceleration(Object_t * obj, ObjectList_t *list, float deltaTime);
int applyAcceleration(Object_t * obj, ObjectList_t *list, float deltaTime);
int applyGravity(Object_t * obj, ObjectList_t *list, float deltaTime);

#endif