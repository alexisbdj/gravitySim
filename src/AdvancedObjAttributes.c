#include "DescriptionToObjects.h"
#include "Utils.h"
#include "ErrorHandling.h"

int objCircularOrbital(DefConversionProcess *process, Token_t *token)
{
    char * value;
    if (getTokenAsName(token, &value) == 0) {
        if (newPostCalcul(process) == NULL) {
            return 1;
        }
        process->currentCalc->targetName = value;
    }
    else {
        return 1;
    }

    return 0;
}

int objOrbitDirX(DefConversionProcess *process, Token_t *token)
{
    float value;
    if (process->currentCalc == NULL) {
        printError("no postCalcul defined");
        return 1;
    }
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentCalc->direction.x = value;
    }
    else {
        return 1;
    }

    return 0;
}

int objOrbitDirY(DefConversionProcess *process, Token_t *token)
{
    float value;
    if (process->currentCalc == NULL) {
        printError("no process defined");
        return 1;
    }
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentCalc->direction.y = value;
    }
    else {
        return 1;
    }

    return 0;
}

int objOrbitDirZ(DefConversionProcess *process, Token_t *token)
{
    float value;
    if (process->currentCalc == NULL) {
        printError("no process defined");
        return 1;
    }
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentCalc->direction.z = value;
    }
    else {
        return 1;
    }

    return 0;
}
