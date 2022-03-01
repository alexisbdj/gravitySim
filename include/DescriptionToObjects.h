#ifndef DESCRIPTION_TO_OBJECTS_H_
#define DESCRIPTION_TO_OBJECTS_H_

#include "LinkedList.h"
#include "Game.h"
#include "ObjectDefinition.h"

typedef struct {
    int success;
    Game_t *game;
    Object_t *currentWorkingObject;
} DefConversionProcess;

int ConvertDescriptionToObjects(LinkedList *objDefs, Game_t *game);
void ProcessDescription(ObjectDefinition_t *def, DefConversionProcess *process);

int ProcessCameraDefinition(ObjectDefinition_t *def, DefConversionProcess *process);
int ProcessRegularDefinition(ObjectDefinition_t *def, DefConversionProcess *process);

int getTokenAsInt(Token_t *token, int *dest);
int getTokenAsFloat(Token_t *token, float *dest);
int getTokenAsName(Token_t *token, char **dest);

// Camera attributes process
int camSetFovy(Game_t *a, Token_t *token);
int camSetPosX(Game_t *a, Token_t *token);
int camSetPosY(Game_t *a, Token_t *token);
int camSetPosZ(Game_t *a, Token_t *token);
int camSetTargetX(Game_t *a, Token_t *token);
int camSetTargetY(Game_t *a, Token_t *token);
int camSetTargetZ(Game_t *a, Token_t *token);


// Obj attributes process
int objSetPosX(DefConversionProcess *process, Token_t *token);
int objSetPosY(DefConversionProcess *process, Token_t *token);
int objSetPosZ(DefConversionProcess *process, Token_t *token);
int objSetVelocityX(DefConversionProcess *process, Token_t *token);
int objSetVelocityY(DefConversionProcess *process, Token_t *token);
int objSetVelocityZ(DefConversionProcess *process, Token_t *token);
int objSetRadius(DefConversionProcess *process, Token_t *token);
int objSetMass(DefConversionProcess *process, Token_t *token);
int objSetColor(DefConversionProcess *process, Token_t *token);

#endif