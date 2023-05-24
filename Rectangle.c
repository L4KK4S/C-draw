#include <stdlib.h>
#include <stdio.h>
#include "Rectangle.h"

// Rectangle fonctions -------------------------------------------------------------------------
Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle *temp_rect = malloc(sizeof(Rectangle));
    temp_rect->point = point;
    temp_rect->width = width;
    temp_rect->height = height;

    return temp_rect;
}

void delete_rectangle(Rectangle * rectangle){
    free(rectangle);
}

void print_rectangle(Rectangle * rectangle){
    printf("RECTANGLE (%d;%d) %d %d", rectangle->point->pos_x, rectangle->point->pos_y, rectangle->height, rectangle->width);
}
// ----------------------------------------------------------------------------------------------
