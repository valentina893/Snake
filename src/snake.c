// snake.c

#include <stdlib.h>
#include <stdio.h>

#include "snake.h"

node *node_create(int x, int y, node *next) {

    struct node *node = (struct node*)malloc(sizeof(struct node));

    node->x = x;
    node->y = y;
    node->next = next;

    return node;

}

snake snake_create(int x, int y) {

    snake snake;

    snake.size = 1;
    snake.head = node_create(x, y, NULL);

    return snake;

}

void snake_move(snake *snake, int dx, int dy, int append) {

    if (snake == NULL || snake->head == NULL) return;

    int temp_x, temp_y;
    int prev_x = snake->head->x, prev_y = snake->head->y;

    snake->head->x += dx, snake->head->y += dy;

    node *curr = snake->head;

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
        curr->next = node_create(prev_x, prev_y, NULL);
        snake->size++;
    }

    return;

}

void snake_delete(snake *snake) {

    if (snake == NULL) return;

    node *curr = snake->head;

    while (curr != NULL) {
        node *temp = curr->next;
        free(curr);
        curr = temp;
    }

    snake->head = NULL;
    snake->size = 0;

    return;

}