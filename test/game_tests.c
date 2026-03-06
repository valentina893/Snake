// game_tests.c

#include "../src/game.h"

int main() {
    game game = game_create("test", 19, 19, 19, 19, 19);
    printf("snake tests\n");
    printf("size of snake struct: %lu\n", sizeof(game.snake));
    printf("size of head node: %lu\n", sizeof(game.snake.head));
    return 0;
}