// snake.h

#ifndef SNAKE_H
#define SNAKE_H

/*
One element of the snake or apple array.
- x, y: current position.
*/
typedef struct node {
    int x, y;
} node;

/*
Abstract array type for representing the snake or apples.
*/
typedef struct array {
    node *data;
    int size;
    int capacity;
} array;

/*
Initializes abstract array type with maxiumum capacity;
*/
array *array_init(int capacity);

/*
Searches array for node n, returns 1 if found, else returns 0.
*/
int array_search(array *array, node n);

/*
Cleans up abstract array type.
*/
void array_delete(array *array);

#endif