#include <math.h>
#include "VectorOperations.h"

Vector3 Vector3_addition(const Vector3 a, const Vector3 b)
{
    return (Vector3){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vector3 Vector3_substraction(const Vector3 a, const Vector3 b)
{
    return (Vector3){a.x - b.x, a.y - b.y, a.z - b.z};
}

Vector3 Vector3_division(const Vector3 a, float value)
{
    return (Vector3){a.x / value, a.y / value, a.z / value};
}

Vector3 Vector3_multiplication(const Vector3 a, float value)
{
    return (Vector3){a.x * value, a.y * value, a.z * value};
}

Vector3 Vector3_normalize(const Vector3 a, float length)
{
    float currentLength = getLength(a);

    return Vector3_multiplication(Vector3_division(a, currentLength), length);
}

Vector3 getDirection(const Vector3 a, const Vector3 b)
{
    return Vector3_normalize(Vector3_substraction(b, a), 1.f);
}

float getLength(const Vector3 a)
{
    return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

float getDistance(const Vector3 a, const Vector3 b)
{
    return getLength(Vector3_substraction(b, a));
}

int Vector3_isNan(const Vector3 a)
{
    return (a.x != a.x || a.y != a.y || a.z != a.z);
}
