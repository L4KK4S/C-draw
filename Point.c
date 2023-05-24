#include <stdlib.h>
#include <stdio.h>
#include "Point.h"


//Point fonctions ---------------------------------------------------------------------------
Point *create_point(int px, int py){
    Point *temp_point = malloc(sizeof(Point));
    temp_point->pos_x = px;
    temp_point->pos_y = py;

    return temp_point;
}

void delete_point(Point * point){
    free(point);
}

void print_point(Point * p){
    printf("POINT (%d;%d)", p->pos_x, p->pos_y);
}
// -------------------------------------------------------------------------------------------
