// game.c

#include <stdlib.h>
#include <stdio.h>

#include "game.h"

game game_create(
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
    game.paused = 0;

    return game;

}

void game_run(game* game) {

    if (game == NULL) return;

    Uint32 last_move_time = SDL_GetTicks();

    while (game->running) {
        input_read(&game->input, &game->running);
        _game_update(game, &last_move_time);
        _game_render(game, 0);
    }

    return;

}

void game_delete(game* game) {

    if (game == NULL) return;

    snake_delete(&game->snake);
    renderer_delete(&game->renderer);

    return;

}

void _game_restart(game* game) {

    if (game == NULL) return;

    snake_delete(&game->snake);

    game->snake = snake_create(rand_int(0, game->grid_width - 1), rand_int(0, game->grid_height - 1));

    game->apple_x = rand_int(0, game->grid_width - 1);
    game->apple_y = rand_int(0, game->grid_height - 1);

    game->input = (input){1, 0, 0};

    game->paused = 0;

    return;

}

void _game_render_snake(game* game, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

    if (game == NULL) return;

    struct snake_node* curr = game->snake.head;

    while (curr != NULL) {
        renderer_drawRect(
            &game->renderer,
            curr->x * (game->window_width / game->grid_width), 
            curr->y  * (game->window_height / game->grid_height), 
            (game->window_width / game->grid_width) - 2, 
            (game->window_height / game->grid_height) - 2,
            r, g, b, a
        );
        curr = curr->next;
    }

    return;

}

void _game_render(game* game, int is_dead) {

    if (game == NULL) return;

    renderer_clear(&game->renderer, 0, 0, 0, 0);

    // render snake
    if (is_dead) {
        _game_render_snake(game, 100, 100, 100, 100);
    } else {
        _game_render_snake(game, 0, 255, 0, 0);
    }

    renderer_drawRect(
        &game->renderer,
        game->apple_x * (game->window_width / game->grid_width), 
        game->apple_y * (game->window_height / game->grid_height), 
        (game->window_width / game->grid_width) - 2, 
        (game->window_height / game->grid_height) - 2, 
        255, 0, 0, 0
    );

    renderer_present(&game->renderer);

}

void _game_paused(game* game) {

    if (game == NULL) return;

    while (game->running && game->paused) {
        input_read(&game->input, &game->running);
        if (game->input.restart) {
            _game_restart(game);
        }
        _game_render(game, 1);
    }

    return;

}

void _game_spawn_apple(game* game) {

    int* x_coords = (int*)malloc(sizeof(int) * ((game->grid_width * game->grid_height) - game->snake.size));
    int* y_coords = (int*)malloc(sizeof(int) * ((game->grid_width * game->grid_height) - game->snake.size));

    int i = 0;

    for (int r = 0; r < game->grid_width; r++) {
        for (int c = 0; c < game->grid_height; c++) {
            int snake_contains = 0;
            snake_node* curr = game->snake.head;
            while (curr != NULL) {
                if (r == curr->x && c == curr->y) {
                    snake_contains = 1;
                    break;
                }
                curr = curr->next;
            }
            if (!snake_contains) {
                x_coords[i] = r;
                y_coords[i] = c;
                i++;
            }
        }
    }

    int pos = rand_int(0, i - 1);
    
    game->apple_x = x_coords[pos];
    game->apple_y = y_coords[pos];

    free(x_coords);
    free(y_coords);

}

int _game_check_collisions(game* game) {

    if (game == NULL) return 1;

    if (game->snake.head->x >= game->grid_width || game->snake.head->x < 0) {
        game->paused = 1;
        return 1;
    }
    if (game->snake.head->y >= game->grid_height || game->snake.head->y < 0) {
        game->paused = 1;
        return 1;
    }

    struct snake_node* curr = game->snake.head->next;

    while (curr != NULL) {
        if (game->snake.head->x == curr->x && game->snake.head->y == curr->y) {
            game->paused = 1;
            return 1;
        }
        curr = curr->next;
    }

    if (game->snake.head->x == game->apple_x && game->snake.head->y == game->apple_y) {
        snake_move(&game->snake, game->input.dir_x, game->input.dir_y, 1);
        _game_spawn_apple(game);
    } else {
        snake_move(&game->snake, game->input.dir_x, game->input.dir_y, 0);
    }

    return 0;

}

void _game_update(game* game, Uint32* last_move_time) {

    if (game == NULL || last_move_time == NULL) return;

    Uint32 now = SDL_GetTicks();

    if (game->input.restart) {
        _game_restart(game);
        return;
    }

    if (now - *last_move_time >= game->move_interval) {
        if (_game_check_collisions(game)) {
            _game_paused(game);
        }
        *last_move_time = now;
    }

    return;

}