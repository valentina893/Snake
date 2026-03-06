// input.h

#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

/*
Input class for keeping track of user input that game engine checks each frame.
*/
typedef struct input {
    int dir_x, dir_y, restart;
} input;

/*
Initializes input class values to zero.
*/
void input_create(input *input);

/*
Called in game_run() loop to check/update user inputs.
*/
void input_read(input *input, int *running);

/*
Helper function for checking which key stroke was pressed and updating the struct.
*/
void _input_keydown(input *input, SDL_Event *event, int *running);

#endif