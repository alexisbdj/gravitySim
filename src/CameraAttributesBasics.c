#include "DescriptionToObjects.h"
#include "Utils.h"

int camSetFovy(Game_t *a, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        a->cam3d.fovy = value;
    }
    else {
        return 1;
    }
    return 0;
}

int camSetPosX(Game_t *a, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        a->cam3d.position.x = value;
    }
    else {
        return 1;
    }
    return 0;
}

int camSetPosY(Game_t *a, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        a->cam3d.position.y = value;
    }
    else {
        return 1;
    }
    return 0;
}

int camSetPosZ(Game_t *a, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        a->cam3d.position.z = value;
    }
    else {
        return 1;
    }

    return 0;
}

int camSetTargetX(Game_t *a, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        a->cam3d.target.x = value;
    }
    else {
        return 1;
    }
    return 0;
}

int camSetTargetY(Game_t *a, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        a->cam3d.target.y = value;
    }
    else {
        return 1;
    }
    return 0;
}

int camSetTargetZ(Game_t *a, Token_t *token)
{
    float value;
    noticeProcess;
    if (getTokenAsFloat(token, &value) == 0) {
        a->cam3d.target.z = value;
    }
    else {
        return 1;
    }
    return 0;
}