#ifndef DRAWY_LINE_H
#define DRAWY_LINE_H
#include "Point.h"

// LINE STRUCTURE
typedef struct line {
    Point *p1;
    Point *p2;
}Line;

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);

#endif
