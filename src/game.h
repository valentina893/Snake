// game.h

#ifndef GAME_H
#define GAME_H

#include "input.h"
#include "random.h"
#include "renderer.h"
#include "snake.h"

/*
Game engine class
*/
typedef struct game {

    renderer renderer;
    snake snake;
    input input;

    int running;
    int paused;

    int apple_x, apple_y;

    int window_width, window_height;
    int grid_width, grid_height;
    
    int move_interval;

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
Helper function for rendering the snake as a certain color.
*/
void _game_render_snake(game* game, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

/*
Helper function for rendering the full current state of the game to the window.
- is_dead helps determine if renderer draws the snake as green (alive) or grey (dead).
*/
void _game_render(game* game, int is_dead);

/*
Helper function that puts game in paused-state loop waiting to be restarted or shut down.
*/
void _game_paused(game* game);

/*
Helper for spawning an apple on a spot where the snake doesn't currently occupy.
- Process is completed by building arrays of all open x and y spots and choosing random index for each.
*/
void _game_spawn_apple(game* game);

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
