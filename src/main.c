#include "Game.h"
#include "ErrorHandling.h"

int main(int argc, char **argv)
{
    Game_t *game;

    if (argc < 2) {
        printError("no file path specified");
        return 1;
    }
    game = Game_create(argv[1]);
    if (!game) {
        return 1;
    }
    Game_run(game);
    Game_destroy(game);
    return 0;
}