#ifndef DRAWY_CIRCLE_H
#define DRAWY_CIRCLE_H
#include "Point.h"

//CIRCLE SHAPE
typedef struct {
    Point *center;
    int radius;
}Circle;

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

#endif
