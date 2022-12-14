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

static void printfAttribute(ObjAttribute_t *attr, void *param)
{
    (void)param;
    printf("\t-> %s = %s (%s)\n", attr->name, attr->value->content, binaryFlag(attr->value->type));

}

void printObjDef(ObjectDefinition_t *a, void *param)
{
    printf("%s\n", a->name);
    LinkedList_foreach(a->attributes, (void*)&printfAttribute, param);
}

void noticeProcess_(const char * functionName, const char * fileName, int line)
{
    printf("POINT : %s:%d -> %s\n", fileName, line, functionName);
}

void printObjStatus(Object_t *a, void *param)
{
    (void)param;
    char *displayName = "undefined";
    if (a->name != NULL)
        displayName = a->name;
    printf("name: %s\n", displayName);
    printf("pos: ");
    printVectorValue(a->pos);
    printf("velocity: ");
    printVectorValue(a->velocity);
    printf("force: ");
    printVectorValue(a->force);
    printf("mass: %f\n", a->mass);
    printf("radius: %f\n", a->radius);
    printf("------------------\n");
}