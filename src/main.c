#include "Game.h"

int main(void)
{
    Game_t *game = Game_create();
    if (!game) {
        return 1;
    }
    Game_run(game);
    Game_destroy(game);
    return 0;
}