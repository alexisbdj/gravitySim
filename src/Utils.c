#include <stdio.h>
#include "Utils.h"

void printVectorValue(const Vector3 a)
{
    printf("(%.2f, %.2f, %.2f)\n", a.x, a.y, a.z);
}

char * binaryFlag(TokenFlag flag)
{
    static char tmpBuffer[10];
    tmpBuffer[9] = 0;
    for (int i = 0; i < 9; i++) {
        tmpBuffer[8 - i] = (((1 << i) & flag) != 0) ? '1':'0';
    }
    return tmpBuffer;
}