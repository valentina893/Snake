// game.h

#ifndef GAME_H
#define GAME_H

#include "input.h"
#include "random.h"
#include "renderer.h"
#include "snake.h"

/*
Game engine class.
*/
typedef struct game {
    
    int running;
    
    snake snake;
    int apple_x, apple_y;

    input input;
    int move_interval;

    renderer renderer;
    int window_width, window_height;
    int grid_width, grid_height;

} game;

/*
Initializes game engine class, called in main.
*/
struct game game_create(
    char* window_title,
    int window_width,
    int window_height,
    int grid_width,
    int grid_height,
    int move_interval
);

/*
Runs game engine class, called in main after game_create().
*/
void game_run(game* game);

/*
Cleans up game engine class, called in main before exiting program.
*/
void game_delete(game* game);

/*
Helper function for resetting game engine class by reinitializing snake and apple.
*/
void game_restart(game* game);

/*
Helper function for updating all elements of the game after user input has been recorded.
*/
void game_update(game* game, Uint32* last_move_time);

/*
Helper function for drawing the snake and apple on screen.
*/
void game_draw_frame(game* game);

void test_draw_grid(game* game);

#endif