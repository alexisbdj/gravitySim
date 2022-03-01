#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ErrorHandling.h"
#include "Game.h"
#include "SystemList.h"
#include "Constants.h"
#include "VectorOperations.h"
#include "FileParsing.h"

const int screenWidth = 1200;
const int screenHeight = 800;

//TODO initialiser ça à partir d'une liste
static System_t *Game_initSystem()
{
    System_t *system = System_push(NULL, resetForce);
    System_t *origin = system;
    if (system == NULL) {
        printError("System init failed");
        return NULL;
    }

    system = System_push(system, applyGravity);
    if (system == NULL) {
        printError("System node add failed");
        System_destroy(origin);
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
    ObjectList_t * list = ObjectList_quickCreate(NULL, (Vector3){0,0,0}, 6, YELLOW);
    ObjectList_t * origin = list;
    if (origin == NULL) {
        printError("ObjectList init failed");
        return NULL;
    }
    list = ObjectList_quickCreate(list, (Vector3){60,0,0}, 1.5, BLUE);
    if (list == NULL) {
        printError("ObjectList init failed");
        ObjectList_destroy(origin);
        return NULL;
    }

    list = ObjectList_quickCreate(list, (Vector3){-60,0,0}, 1.5, PURPLE);
    if (list == NULL) {
        printError("ObjectList init failed");
        ObjectList_destroy(origin);
        return NULL;
    }

    list = ObjectList_quickCreate(list, (Vector3){120,0,0}, 1.5, GREEN);
    if (list == NULL) {
        printError("ObjectList init failed");
        ObjectList_destroy(origin);
        return NULL;
    }
    return list;
}

Game_t *Game_create(const char * descriptorPath)
{
    Game_t *game = malloc(sizeof(Game_t));

    if (game == NULL) {
        printError("malloc failed");
        return NULL;
    }

    if (parseFile(descriptorPath, game) != 0) {
        free(game);
        printError("failed to parse descriptor file");
        return NULL;
    }

    game->objectList = NULL;
    game->system = NULL;

    return game;

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

    game->objectList->next->element->velocity.z = -50;
    game->objectList->next->next->element->velocity.z = 50;
    game->objectList->next->next->next->element->velocity = Vector3_normalize((Vector3){0, 1, 2}, sqrtf(((392e13 * Gconst) / (120))));
    game->objectList->element->mass = 392e13;
    game->cam3d = (Camera3D){0};
    // game->cam3d.position = (Vector3){ 0.0f, 6.0f, 20.0f };
    // game->cam3d.position = (Vector3){ 0.0f, 55.0f, 1.0f };
    // game->cam3d.position = (Vector3){ 0.0f, 120.0f, 400.0f };
    // game->cam3d.position = (Vector3){ 0.0f, 255.0f, 1.0f };
    // game->cam3d.position = (Vector3){ 0.0f, 120.0f, 400.0f };
    // game->cam3d.position = (Vector3){ 0.0f, 0, 400.0f };
    game->cam3d.position = (Vector3){ 0.0f, 90.0f, 300.0f };
    game->cam3d.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    game->cam3d.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    game->cam3d.fovy = 45.0f;
    game->cam3d.projection = CAMERA_PERSPECTIVE;


    // InitWindow(screenWidth, screenHeight, "potit test");

    // SetTargetFPS(60);
    return game;
}

int Game_run(Game_t *game)
{
    (void)game;
    // while (!WindowShouldClose())
    // {
    //     float deltaTime = GetFrameTime();
    //     System_processFrame(game->system, game->objectList, deltaTime);

    //     BeginDrawing();
    //     ClearBackground(BLACK);
    //     BeginMode3D(game->cam3d);
    //     ObjectList_renderAll(game->objectList);
    //     DrawGrid(80, 8.0f);
    //     EndMode3D();
    //     DrawFPS(10, 10);
    //     EndDrawing();
    // }
    return 0;
}

void Game_destroy(Game_t *game)
{
    ObjectList_destroy(game->objectList);
    System_destroy(game->system);
    // CloseWindow();
    free(game);
}