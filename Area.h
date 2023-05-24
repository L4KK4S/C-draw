#ifndef DRAWY_AREA_H
#define DRAWY_AREA_H

#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "Line.h"
#include "Square.h"
#include "Rectangle.h"
#include "circle.h"
#include "Polygon.h"
#include "Shape.h"
#include "Id.h"
#include "Pixel.h"

#define SHAPE_MAX 100
#define BOOL int

// Structure Area -----------------------------------------------------------------------

// Définition de la structure
struct area {
    unsigned int width;
    unsigned int height;
    BOOL** mat;
    Shape* shapes[SHAPE_MAX];
    int nb_shape;
};
typedef struct area Area;

// Fonctions sur l'area
Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void print_area(Area* area);
void draw_area(Area* area);
Pixel*** create_shape_to_pixel(Shape * shape, Pixel*** pixel_tab, int* nb_pixels);


// --------------------------------------------------------------------------------------

#endif //DRAWY_AREA_H
