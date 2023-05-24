#ifndef DRAWY_PIXEL_H
#define DRAWY_PIXEL_H

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
#include "Area.h"

// Structure Pixel ----------------------------------------------------------------------

// Définition de la structure
struct pixel {
    int px;
    int py;
};
typedef struct pixel Pixel;

// Fonctions associées
Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel * pixel);

// Fonctionhs sur les formes
void pixel_point(Point* point, Pixel*** pixel_tab, int* nb_pixels);
void pixel_line(Line* line, Pixel*** pixel_tab, int* nb_pixels);
void pixel_circle(Circle* shape, Pixel*** pixel_tab, int *nb_pixels);
void pixel_square(Square* square, Pixel*** pixel_tab, int* nb_pixels);
void pixel_rectangle(Rectangle* rectangle, Pixel*** pixel_tab, int* nb_pixels);
void pixel_polygon(Polygon* polygon, Pixel*** pixel_tab, int* nb_pixels);

// -------------------------------------------------------------------------------------

#endif //DRAWY_PIXEL_H
