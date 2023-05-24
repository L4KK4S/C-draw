#ifndef DRAWY_POLYGON_H
#define DRAWY_POLYGON_H
#include "Point.h"

//POLYGON STRUCUTRE
typedef struct polygon {
    int n;
    Point ** points;
}Polygon;

Polygon *create_polygon(int n, Point** tab);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

#endif
