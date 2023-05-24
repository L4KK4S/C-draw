#include <stdlib.h>
#include <stdio.h>
#include "Line.h"

//Line fonctions -----------------------------------------------------------------------------
Line *create_line(Point * p1, Point * p2){
    Line *temp_line = malloc(sizeof(Line));
    temp_line->p1= p1;
    temp_line->p2= p2;

    return temp_line;
}

void delete_line(Line * line){
    free(line);
}

void print_line(Line * line){
    printf("LINE (%d;%d) (%d;%d)", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}
// ---------------------------------------------------------------------------------------------
