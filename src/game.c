// game.c

#include <stdio.h>

#include "game.h"

struct game game_create(
    char* window_title,
    int window_width,
    int window_height,
    int grid_width,
    int grid_height,
    int move_interval
)
{

    game game;

    rand_seed();

    game.snake = snake_create(rand_int(0, grid_width - 1), rand_int(0, grid_height - 1));

    game.apple_x = rand_int(0, grid_width - 1);
    game.apple_y = rand_int(0, grid_height - 1);

    game.input = input_create();
    game.move_interval = move_interval;

    renderer_create(&game.renderer, window_title, window_width, window_height);

    game.window_width = window_width;
    game.window_height = window_height;

    game.grid_width = grid_width;
    game.grid_height = grid_height;

    game.running = 1;

    return game;

}

void game_run(game* game) {

    if (game == NULL) return;

    Uint32 last_move_time = SDL_GetTicks();  // record initial time

    while (game->running) {
        // input_read()
        // game_update()
        // game_draw_frame()


        input_read(&game->input, &game->running);
        game_update(game, &last_move_time);
        game_draw_frame(game);
    }

}

void game_delete(game* game) {

    if (game == NULL) return;

    snake_delete(&game->snake);
    renderer_delete(&game->renderer);

    return;

}

void game_restart(game* game) {

    if (game == NULL) return;

    snake_delete(&game->snake);

    game->snake = snake_create(rand_int(0, game->grid_width - 1), rand_int(0, game->grid_height - 1));

    game->apple_x = rand_int(0, game->grid_width - 1);
    game->apple_y = rand_int(0, game->grid_height - 1);

    game->input = (input){1, 0, 0};

    return;

}

void game_update(game* game, Uint32* last_move_time) {

    if (game == NULL) return;

    Uint32 now = SDL_GetTicks();
    if (now - *last_move_time >= game->move_interval) {
        if (game->snake.head->x == game->apple_x && game->snake.head->y == game->apple_y) {
            snake_move(&game->snake, game->input.dir_x, game->input.dir_y, 1);
            game->apple_x = rand_int(0, game->grid_width - 1);
            game->apple_y = rand_int(0, game->grid_height - 1);
        } else {
            snake_move(&game->snake, game->input.dir_x, game->input.dir_y, 0);
        }
        *last_move_time = now;
    }

    if (game->input.restart) game_restart(game);

}

void game_draw_frame(game* game) {

    if (game == NULL) return;

    renderer_clear(&game->renderer, 0, 0, 0, 0);

    int square_x = game->window_width / game->grid_width;
    int square_y = game->window_height / game->grid_height;

    // draw snake
    struct snake_node* curr = game->snake.head;

    while (curr != NULL) {
        renderer_drawRect(&game->renderer, curr->x * square_x, curr->y  * square_y, square_x - 2, square_y - 2, 0, 255, 0, 0);
        curr = curr->next;
    }

    // draw apple
    renderer_drawRect(&game->renderer, game->apple_x * square_x, game->apple_y * square_y, square_x - 2, square_y - 2, 255, 0, 0, 0);

    renderer_present(&game->renderer);

    return;

}

void test_draw_grid(game* game) {

    int square_x = game->window_width / game->grid_width;
    int square_y = game->window_height / game->grid_height;

    renderer_clear(&game->renderer, 0, 0, 0, 0);

    for (int i = 0; i < game->grid_width; i++) {
        for (int j = 0; j < game->grid_height; j++) {
            renderer_drawRect(&game->renderer, i * square_x, j  * square_y, square_x - 2, square_y - 2, 0, 255, 0, 0);
        }
    }

    renderer_present(&game->renderer);

}