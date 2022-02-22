#ifndef GAME_H_
#define GAME_H_

#include <raylib.h>
#include "ObjectList.h"
#include "System.h"

typedef struct {
    Camera3D cam3d;
    ObjectList_t *objectList;
    System_t *system;
} Game_t;

Game_t *Game_create(const char * descriptorPath);

int Game_run(Game_t *game);

void Game_destroy(Game_t *game);

#endif