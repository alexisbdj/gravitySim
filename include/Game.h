#ifndef GAME_H_
#define GAME_H_

#include <raylib.h>
#include "ObjectList.h"

typedef struct {
    Camera3D cam3d;
    ObjectList_t *objectList;
} Game_t;

Game_t *Game_create();

int Game_run(Game_t *game);

void Game_destroy(Game_t *game);

#endif