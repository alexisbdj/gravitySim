#include "DescriptionToObjects.h"
#include "Utils.h"

int objSetPosX(DefConversionProcess *process, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentWorkingObject->pos.x = value;
    }
    else {
        return 1;
    }

    return 0;
}

int objSetPosY(DefConversionProcess *process, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentWorkingObject->pos.y = value;
    }
    else {
        return 1;
    }

    return 0;
}
int objSetPosZ(DefConversionProcess *process, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentWorkingObject->pos.z = value;
    }
    else {
        return 1;
    }

    return 0;
}
int objSetVelocityX(DefConversionProcess *process, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentWorkingObject->velocity.x = value;
    }
    else {
        return 1;
    }

    return 0;
}
int objSetVelocityY(DefConversionProcess *process, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentWorkingObject->velocity.y = value;
    }
    else {
        return 1;
    }

    return 0;
}
int objSetVelocityZ(DefConversionProcess *process, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentWorkingObject->velocity.z = value;
    }
    else {
        return 1;
    }

    return 0;
}
int objSetRadius(DefConversionProcess *process, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentWorkingObject->radius = value;
    }
    else {
        return 1;
    }

    return 0;
}

int objSetMass(DefConversionProcess *process, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        process->currentWorkingObject->mass = value;
    }
    else {
        return 1;
    }

    return 0;
}
