#ifndef DRAWY_SQUARE_H
#define DRAWY_SQUARE_H
#include "Point.h"

// SQUARE STRUCTURE
typedef struct square {
    Point *point;
    int lenght;
}Square;

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);


#endif
