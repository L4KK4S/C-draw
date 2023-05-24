#ifndef DRAWY_POINT_H
#define DRAWY_POINT_H

// POINT STRUCTURE
typedef struct{
    int pos_x;
    int pos_y;
}Point;

Point *create_point(int px, int py);
void delete_point(Point * point);
void print_point(Point * p);

#endif

