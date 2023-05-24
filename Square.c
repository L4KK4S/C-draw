#include <stdlib.h>
#include <stdio.h>
#include "Square.h"

// Square fonctions ----------------------------------------------------------------------------
Square *create_square(Point * point, int length){
    Square *temp_square = malloc(sizeof(Square));
    temp_square->point = point;
    temp_square->lenght = length;

    return temp_square;
}

void delete_square(Square * square){
    free(square);
}

void print_square(Square * square){
    printf("SQUARE (%d;%d) %d", square->point->pos_x, square->point->pos_y, square->lenght);
}
// ---------------------------------------------------------------------------------------------
