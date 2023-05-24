#ifndef DRAWY_RECTANGLE_H
#define DRAWY_RECTANGLE_H
#include "Point.h"

// RECTANGLE STRUCTURE
typedef struct rectangle {
    Point *point;
    int width;
    int height;
}Rectangle;

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

#endif
