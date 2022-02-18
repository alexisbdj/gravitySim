#ifndef VECTOR_OPERATIONS_H_
#define VECTOR_OPERATIONS_H_

#include "raylib.h"

Vector3 Vector3_addition(const Vector3 a, const Vector3 b);
Vector3 Vector3_substraction(const Vector3 a, const Vector3 b);
Vector3 Vector3_division(const Vector3 a, float value);
Vector3 Vector3_multiplication(const Vector3 a, float value);
Vector3 Vector3_normalize(const Vector3 a, float length);


Vector3 getDirection(const Vector3 a, const Vector3 b);
float getLength(const Vector3 a);
float getDistance(const Vector3 a, const Vector3 b);

#endif