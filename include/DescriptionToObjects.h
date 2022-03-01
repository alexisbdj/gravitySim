#ifndef DESCRIPTION_TO_OBJECTS_H_
#define DESCRIPTION_TO_OBJECTS_H_

#include "LinkedList.h"
#include "Game.h"
#include "ObjectDefinition.h"

typedef struct {
    int success;
    Game_t *game;
} DefConvertionProcess;

int ConvertDescriptionToObjects(LinkedList *objDefs, Game_t *game);
void ProcessDescription(ObjectDefinition_t *def, DefConvertionProcess *process);

int ProcessCameraDefinition(ObjectDefinition_t *def, DefConvertionProcess *process);
int ProcessRegularDefinition(ObjectDefinition_t *def, DefConvertionProcess *process);

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

#endif