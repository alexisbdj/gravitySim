#include <string.h>
#include "DescriptionToObjects.h"
#include "Algorithm.h"
#include "ErrorHandling.h"

static const fncPtr attrProcessList[] = {
    {"posX", (void*) &objSetPosX},
    {"posY", (void*) &objSetPosY},
    {"posZ", (void*) &objSetPosZ},
    {"velocityX", (void*) &objSetVelocityX},
    {"velocityY", (void*) &objSetVelocityY},
    {"velocityZ", (void*) &objSetVelocityZ},
    {"radius", (void*) &objSetRadius},
    {"mass", (void*) &objSetMass},
    {"color", (void*) &objSetColor},
    {"circularOrbit", (void*) &objCircularOrbital},
    {"orbitDirX", (void*) &objOrbitDirX},
    {"orbitDirY", (void*) &objOrbitDirY},
    {"orbitDirZ", (void*) &objOrbitDirZ},
};

static const int processListCount = 13;

static void ProcessObjAttribute(ObjAttribute_t *attr, DefConversionProcess *process)
{
    fncSwitchInput input;
    input.a = process;
    input.b = (void*)attr->value;
    input.name = attr->name;

    if (switchFncFromArray(processListCount, attrProcessList, &input) != 0) {
        printError("unknown object attribute");
        process->success = 0;
    }
}

int ProcessRegularDefinition(ObjectDefinition_t *def, DefConversionProcess *process)
{
    process->currentCalc = NULL;
    process->game->objectList = ObjectList_create(process->game->objectList, &process->currentWorkingObject);
    process->currentWorkingObject->name = strdup(process->currentObjName);
    if (process->game->objectList == NULL || process->currentWorkingObject == NULL) {
        return 1;
    }
    LinkedList_foreach(def->attributes, (void*) ProcessObjAttribute, process);
    process->currentWorkingObject = NULL;
    process->currentCalc = NULL;
    return 0;
}
