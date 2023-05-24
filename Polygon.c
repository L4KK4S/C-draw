#include <stdlib.h>
#include <stdio.h>
#include "Polygon.h"


// Polygon fonctions ----------------------------------------------------------------------------
Polygon* create_polygon(int n, Point ** tab){
    Polygon* temp_polygon = malloc(sizeof(Polygon));
    temp_polygon->n = n;
    temp_polygon->points = tab;

     if (temp_polygon->points[0] != temp_polygon->points[n-1]){
        (temp_polygon->n)++;
        temp_polygon->points = (Point**) realloc(temp_polygon->points, sizeof(Point*) * temp_polygon->n);
        temp_polygon->points[n] = temp_polygon->points[0];
    }

    return temp_polygon;
}

void delete_polygon(Polygon * polygon){
    free(polygon);
}

void print_polygon(Polygon * polygon){

    printf("POLYGON");
    for (int i = 0; i < polygon->n; i++){
        printf(" (%d;%d)", polygon->points[i]->pos_x, polygon->points[i]->pos_y);
    }

}
// ----------------------------------------------------------------------------------------------
