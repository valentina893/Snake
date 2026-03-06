// snake.h

#ifndef SNAKE_H
#define SNAKE_H

/*
One element of the snake or apple array.
- x, y: current position.
- next: next node furthest from head in direction of travel.
*/
typedef struct node {
    struct node *next;
    int x, y;
} node;

/*
Snake entity represented by a linked list. Traversed from head -> tail.
- size: total nodes in snake entity.
- head: front-most node in direction of traversal.
*/
typedef struct snake {
    struct node *head;
    int size;
} snake;

/*
Creates a new node.
*/
node *node_create(int x, int y, struct node *next);

/*
Creates a snake entity of size 1 at specified position.
*/
snake snake_create(int x, int y);

/*
Moves each node in snake array starting from head.
*/
void snake_move(snake *snake, int dx, int dy, int append);

/*
Cleans dynamically allocated memory in snake entity.
*/
void snake_delete(snake *snake);

#endif