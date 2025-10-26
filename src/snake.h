// snake.h

#ifndef SNAKE_H
#define SNAKE_H

/*
One element of the snake entity.
- x, y: current position.
- next: next snake_node furthest from head in direction of travel.
*/
typedef struct snake_node {
    struct snake_node* next;
    int x, y;
} snake_node;

/*
Snake entity represented by a linked list. Traversed from head -> tail.
- size: total snake_nodes in snake entity.
- head: front-most snake_node in direction of traversal.
*/
typedef struct snake {
    snake_node* head;
    int size;
} snake;

/*
Creates a new snake_node.
*/
snake_node* snake_node_create(int x, int y, struct snake_node* next);

/*
Creates a snake entity of size 1 at specified position.
*/
snake snake_create(int x, int y);

/*
Moves each snake_node in snake_entity starting from head.
*/
void snake_move(struct snake* snake, int dx, int dy, int append);

/*
Cleans dynamically allocated memory in snake entity.
*/
void snake_delete(struct snake* snake);

/*
Displays the snake entity for debugging purposes.
*/
void snake_print(struct snake* snake);

#endif