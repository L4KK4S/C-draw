#include <stdlib.h>
#include <stdio.h>
#include "Circle.h"

// Circle fonctions -----------------------------------------------------------------------------
Circle *create_circle(Point * center, int radius){
    Circle *temp_circle = malloc(sizeof(Circle));
    temp_circle->center = center;
    temp_circle->radius = radius;

    return temp_circle;
}

void delete_circle(Circle * circle){
    free(circle);
}
void print_circle(Circle * circle){
    printf("CIRCLE (%d;%d) %d", circle->center->pos_x, circle->center->pos_y, circle->radius);
}
// ----------------------------------------------------------------------------------------------
