// main.c

#include "game.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

#define GRID_WIDTH 20
#define GRID_HEIGHT 20

#define MOVE_INTERVAL 200

int main() {
    game game = game_create("Snake", WINDOW_WIDTH, WINDOW_HEIGHT, GRID_WIDTH, GRID_HEIGHT, MOVE_INTERVAL);
    game_run(&game);
    game_delete(&game);
    return 0;
}