// snake.c

#include <stdlib.h>
#include <stdio.h>

#include "snake.h"

array *array_init(int capacity) {

    array *array = (struct array*)malloc(sizeof(struct array));
    array->data = (struct node*)malloc(sizeof(struct node));
    array->size = 0;
    array->capacity = capacity;

    return array;

}

int array_search(array *array, node n) {

    if (array != NULL && array->data != NULL) {
        for (int i = 0; i < array->capacity; i++) {
            if (array->data[i].x == n.x && array->data[i].y == n.y) {
                return 1;
            }
        }
    }

    return 0;

}

void array_delete(array *array) {

    if (array != NULL) {
        if (array->data != NULL) {
            free(array->data);
            array->size, array->capacity = 0;
        }
        free(array);
    }

}