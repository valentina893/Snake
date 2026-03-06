// snake_tests.c

#include <stdio.h>

#include "../src/snake.h"

void snake_print(snake *snake) {

    if (snake == NULL) return;

    node *curr = snake->head;

    while (curr != NULL) {
        printf("(%d, %d) -> ", curr->x, curr->y);
        curr = curr->next;
    }
    
    printf("NULL\n");

    return;

}

int main() {
    snake snake = snake_create(1, 1);
    printf("snake tests\n");
    printf("size of snake struct: %lu\n", sizeof(snake));
    printf("size of head node: %lu\n", sizeof(snake.head));
    return 0;
}