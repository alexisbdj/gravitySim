#include <string.h>
#include "DescriptionToObjects.h"
#include "Algorithm.h"

const fncPtr attrProcessList[] = {
    {"fovy", (void*) &camSetFovy},
    {"posX", (void*) &camSetPosX},
    {"posY", (void*) &camSetPosY},
    {"posZ", (void*) &camSetPosZ},
    {"targetX", (void*) &camSetTargetX},
    {"targetY", (void*) &camSetTargetY},
    {"targetZ", (void*) &camSetTargetZ},
    //TODO up attribute
};
const int processListCount = 7;

static void ProcessCameraAttribute(ObjAttribute_t *attr, DefConvertionProcess *process)
{
    fncSwitchInput input;
    input.a = process->game;
    input.b = (void*)attr->value;
    input.name = attr->name;

    if (switchFncFromArray(processListCount, attrProcessList, &input) != 0) {
        process->success = 0;
    }
}

int ProcessCameraDefinition(ObjectDefinition_t *def, DefConvertionProcess *process)
{
    LinkedList_foreach(def->attributes, (void*) ProcessCameraAttribute, process);
    return 0;
}
