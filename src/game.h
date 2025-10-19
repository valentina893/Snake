// game.h

#ifndef GAME_H
#define GAME_H

#include "input.h"
#include "random.h"
#include "renderer.h"
#include "snake.h"

typedef struct game {

    int running;
    int paused;

    snake snake;
    int apple_x, apple_y;

    input input;
    int move_interval;

    renderer renderer;
    int window_width, window_height;
    int grid_width, grid_height;

} game;

/*
Initializes game engine class, called at the start of main.
*/
game game_create(
    char* window_title,
    int window_width,
    int window_height,
    int grid_width,
    int grid_height,
    int move_interval
);

/*
Main program loop for running the game engine, called after in main after initializing game.
*/
void game_run(game* game);

/*
Cleans up game engine class, called in main before exiting program.
*/
void game_delete(game* game);

/*
Helper function that re-initializes components of the game engine class, excluding the renderer class.
*/
void _game_restart(game* game);

/*
Helper function for rendering the full current state of the game to the window with custom color for snake.
*/
void _game_render(game* game, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

/*
Helper function that puts game in paused-state loop waiting to be restarted or shut down.
*/
void _game_paused(game* game);

/*
Helper function that checks snake entity's head coordinates with walls, apple, and other snake pieces.
- Sets paused to 1 and returns 1 if snake collides with itself or a wall.
- Appends to the snake if it collides with an apple.
- By default moves the snake in user's desired direction if no collisions occur and returns 0.
*/
int _game_check_collisions(game* game);

/*
Helper function that updates all components of the game engine.
*/
void _game_update(game* game, Uint32* last_move_time);

#endif