// snake.c

#include <stdlib.h>
#include <stdio.h>

#include "snake.h"

struct snake_node* snake_node_create(int x, int y, struct snake_node* next) {

    struct snake_node* snake_node = (struct snake_node*)malloc(sizeof(snake_node));

    snake_node->x = x;
    snake_node->y = y;
    snake_node->next = next;

    return snake_node;

}

struct snake snake_create(int x, int y) {

    snake snake;

    snake.size = 1;
    snake.head = snake_node_create(x, y, NULL);

    return snake;

}

void snake_move(struct snake* snake, int dx, int dy, int append) {

    if (snake == NULL || snake->head == NULL) return;

    int temp_x, temp_y;
    int prev_x = snake->head->x, prev_y = snake->head->y;

    snake->head->x += dx, snake->head->y += dy;

    struct snake_node* curr = snake->head;

    while (curr->next != NULL) {

        // Move to next node
        curr = curr->next;
        
        // Save current node's coordinates
        temp_x = curr->x;
        temp_y = curr->y;

        // Update current node to previous position
        curr->x = prev_x;
        curr->y = prev_y;

        // Shift the "previous" values forward
        prev_x = temp_x;
        prev_y = temp_y;
        
    }

    if (append) {
        curr->next = snake_node_create(prev_x, prev_y, NULL);
        snake->size++;
    }

    return;

}

void snake_delete(struct snake* snake) {

    if (snake == NULL) return;

    struct snake_node* curr = snake->head;

    while (curr != NULL) {
        struct snake_node* temp = curr->next;
        free(curr);
        curr = temp;
    }

    snake->head = NULL;
    snake->size = 0;

    return;

}

void snake_print(struct snake* snake) {

    if (snake == NULL) return;

    struct snake_node* curr = snake->head;

    while (curr != NULL) {
        printf("(%d, %d) -> ", curr->x, curr->y);
        curr = curr->next;
    }
    
    printf("NULL\n");

    return;

}