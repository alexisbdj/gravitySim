#include <stdlib.h>
#include <stdio.h>
#include "ErrorHandling.h"
#include "Game.h"
#include "SystemList.h"

const int screenWidth = 1200;
const int screenHeight = 800;

static System_t *Game_initSystem()
{
    System_t *system = System_push(NULL, resetForce);
    System_t *origin = system;
    if (system == NULL) {
        printError("System init failed");
        return NULL;
    }

    system = System_push(system, calculateAcceleration);
    if (system == NULL) {
        printError("System node add failed");
        System_destroy(origin);
        return NULL;
    }

    system = System_push(system, applyAcceleration);
    if (system == NULL) {
        printError("System node add failed");
        System_destroy(origin);
        return NULL;
    }

    system = System_push(system, applyVelocity);
    if (system == NULL) {
        printError("System node add failed");
        System_destroy(origin);
        return NULL;
    }
    return system;
}

static ObjectList_t *Game_initObjects()
{
    ObjectList_t * list = ObjectList_create(NULL, (Vector3){0,0,0}, 2, YELLOW);
    ObjectList_t * origin = list;
    if (origin == NULL) {
        printError("ObjectList init failed");
        return NULL;
    }
    list = ObjectList_create(list, (Vector3){10,0,0}, 0.5, BLUE);
    if (origin == NULL) {
        printError("ObjectList init failed");
        ObjectList_destroy(origin);
        return NULL;
    }
    return list;
}

Game_t *Game_create()
{
    Game_t *game = malloc(sizeof(Game_t));

    if (game == NULL) {
        printError("malloc failed");
        return NULL;
    }

    game->objectList = Game_initObjects(NULL, (Vector3){0,0,0}, 2, YELLOW);
    if (game->objectList == NULL) {
        printError("ObjectList init failed");
        free(game);
        return NULL;
    }

    game->system = Game_initSystem();
    if (game->system == NULL) {
        printError("System init failed");
        ObjectList_destroy(game->objectList);
        free(game);
        return NULL;
    }

    game->objectList->next->element->velocity.z = -2;
    game->cam3d = (Camera3D){0};
    // game->cam3d.position = (Vector3){ 0.0f, 6.0f, 20.0f };
    game->cam3d.position = (Vector3){ 0.0f, 55.0f, 1.0f };
    game->cam3d.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    game->cam3d.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    game->cam3d.fovy = 45.0f;
    game->cam3d.projection = CAMERA_PERSPECTIVE;


    InitWindow(screenWidth, screenHeight, "potit test");

    SetTargetFPS(60);
    return game;
}

int Game_run(Game_t *game)
{
    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        System_processFrame(game->system, game->objectList, deltaTime);

        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(game->cam3d);
        ObjectList_renderAll(game->objectList);
        DrawGrid(40, 1.0f);
        EndMode3D();
        DrawFPS(10, 10);
        EndDrawing();
    }
    return 0;
}

void Game_destroy(Game_t *game)
{
    free(game);
}