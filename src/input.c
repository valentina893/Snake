// input.c

#include "input.h"

input input_create() {
    return (input){1, 0, 0};
}

void input_read(input* input, int* running) {

    if (input == NULL || running == NULL) return;

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *running = 0;
                break;
            case SDL_KEYDOWN:
                _input_keydown(input, &event, running);
                break;
        }
    }

    return;

}

void _input_keydown(input* input, SDL_Event* event, int* running) {

    if (input == NULL || event == NULL || running == NULL) return;

    switch (event->key.keysym.scancode) {
        case SDL_SCANCODE_W:
        case SDL_SCANCODE_UP:
            input->dir_x = 0; 
            input->dir_y = -1;
            break;
        case SDL_SCANCODE_A:
        case SDL_SCANCODE_LEFT:
            input->dir_x = -1; 
            input->dir_y = 0;
            break;
        case SDL_SCANCODE_S:
        case SDL_SCANCODE_DOWN:
            input->dir_x = 0; 
            input->dir_y = 1;
            break;
        case SDL_SCANCODE_D:
        case SDL_SCANCODE_RIGHT:
            input->dir_x = 1; 
            input->dir_y = 0;
            break;
        case SDL_SCANCODE_R:
            input->restart = 1;
            break;
        case SDL_SCANCODE_ESCAPE:
            *running = 0;    
            break;
        default:
            break;
    }

    return;

}