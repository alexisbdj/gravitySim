#ifndef UTILS_H_
#define UTILS_H_

#include "raylib.h"
#include "FileParsing.h"
#include "ObjectDefinition.h"

void printVectorValue(const Vector3 a);
char * binaryFlag(TokenFlag flag);
void printObjDef(ObjectDefinition_t *a, void *param);

void noticeProcess_(const char * functionName, const char * fileName, int line);

#define noticeProcess noticeProcess_(__FUNCTION__, __FILE__, __LINE__)

#endif