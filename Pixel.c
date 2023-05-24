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
#include "Pixel.h"

Pixel* create_pixel(int px, int py) {

    Pixel* temp_pixel = (Pixel*)malloc(sizeof(Pixel));
    temp_pixel->px = px;
    temp_pixel->py = py;

    return temp_pixel;
}

void delete_pixel(Pixel* pixel){
    free(pixel);
}

//
// ################################################################################################################################################################################################
//
void pixel_point(Point* point, Pixel*** pixel_tab, int* nb_pixels){

    // verification du nombre de pixels déjà présents pour (re)allouer la mémoire en conséquence
    if (!*nb_pixels){
        *pixel_tab = (Pixel**) malloc(sizeof(Pixel*));
    }
    else{
        *pixel_tab = (Pixel**) realloc(*pixel_tab, sizeof(Pixel*) * ((*nb_pixels)+1));
    }

    // créer un pixel associé au point, le mettre dans le tableau de pixels et incrémenter le nombre de pixels
    (*pixel_tab)[*nb_pixels] = create_pixel((*point).pos_x, (*point).pos_y);
    (*nb_pixels)++;

}

void pixel_line(Line* line, Pixel*** pixel_tab, int* nb_pixels) {

    // on initialise xa, xb, ya, yb
    int xa = line->p1->pos_x, ya = line->p1->pos_y;
    int xb = line->p2->pos_x, yb = line->p2->pos_y;

    // si jamais xb < xa on inverse les deux droites
    if (xb < xa) {
        int temp = xb;
        xb = xa;
        xa = temp;
        temp = yb;
        yb = ya;
        ya = temp;
    }

    // on initialise dx et dy
    int dx = xb - xa;
    int dy = yb - ya;

    // on initialise dmin et dmax
    int dmin, dmax;
    if (dx < abs(dy)) {
        dmin = dx;
        dmax = abs(dy);
    } else {
        dmin = abs(dy);
        dmax = dx;
    }

    // on calcule le nombre de segments à tracer
    int nb_segs = dmin + 1;

    // on calcule la taille de ces segments
    int segs_lenght = (dmax + 1) / (dmin + 1);
    int restants = (dmax + 1) % (dmin + 1) ;

    // on crée donc un tableau segments comportant nb_segs éléments, et on initialise tous ses éléments avec la taille de de base
    int *segments = (int *) malloc(sizeof(int) * nb_segs);
    for (int i = 0; i < nb_segs; ++i) {
        segments[i] = segs_lenght;
    }

    // on calcule les pixels à répartir
    int *cumuls = (int *) malloc(nb_segs * sizeof(int));
    cumuls[0] = 0;
    for (int i = 1; i < nb_segs; i++) {
        cumuls[i] = (( (i+1) * restants) % (dmin + 1) < ((i - 1) * restants) % (dmin + 1));
        segments[i] = segments[i] + cumuls[i];
    }


    // on crée des cordonnéees qui seriront à placer les points
    int x = xa, y = ya;

    // placer le premier point
    Point *temp_point = create_point(x, y);
    pixel_point(temp_point, pixel_tab, nb_pixels);

    // fonctionnement de l'algorithme de tracé de ligne de Flasque
    if (dy < 0) {

        if (dx > abs(dy)) {
            for (int i = 0; i < nb_segs; i++) {
                for (int j = 0; j < segments[i]; j++) {

                    temp_point->pos_x = x++, temp_point->pos_y = y;
                    pixel_point(temp_point, pixel_tab, nb_pixels);

                }
                y--;

            }
        }

        else
        {
            for (int i = 0; i < nb_segs; i++) {
                for (int j = 0; j < segments[i]; j++) {

                    temp_point->pos_x = x, temp_point->pos_y = y--;
                    pixel_point(temp_point, pixel_tab, nb_pixels);

                }
                x++;

            }
        }

    }

    else
    {
        if (dx > dy){
            for (int i = 0; i < nb_segs; i++) {
                for (int j = 0; j < segments[i]; j++) {

                    temp_point->pos_x = x++, temp_point->pos_y = y;
                    pixel_point(temp_point, pixel_tab, nb_pixels);

                }
                y++;

            }
        }
        else {
            for (int i = 0; i < nb_segs; i++) {
                for (int j = 0; j < segments[i]; j++) {

                    temp_point->pos_x = x, temp_point->pos_y = y++;
                    pixel_point(temp_point, pixel_tab, nb_pixels);

                }

                x++;
            }
        }
    }

}


void pixel_circle(Circle *circle, Pixel ***pixel_tab, int *nb_pixels) {

    // on instancie les variables nécessaires à l'algorithme de tracé de cercle d'Andres
    int x = 0;
    int y = circle->radius;
    int d = circle->radius - 1;
    int c = circle->center->pos_x;

    // on alloue la mémoire au pixel_tab
    *pixel_tab = (Pixel **) malloc((c * 2000) * sizeof(Pixel *));

    while (y >= x) {

        // on crée les 8 points l'algorithme de tracé de cercle d'Andres
        Point *p1 = create_point(circle->center->pos_x + x, circle->center->pos_y + y);
        Point *p2 = create_point(circle->center->pos_x + y, circle->center->pos_y + x);
        Point *p3 = create_point(circle->center->pos_x - x, circle->center->pos_y + y);
        Point *p4 = create_point(circle->center->pos_x - y, circle->center->pos_y + x);
        Point *p5 = create_point(circle->center->pos_x + x, circle->center->pos_y - y);
        Point *p6 = create_point(circle->center->pos_x + y, circle->center->pos_y - x);
        Point *p7 = create_point(circle->center->pos_x - x, circle->center->pos_y - y);
        Point *p8 = create_point(circle->center->pos_x - y, circle->center->pos_y - x);

        // on trace ces 8 pooints
        pixel_point(p1, pixel_tab, nb_pixels);
        pixel_point(p2, pixel_tab, nb_pixels);
        pixel_point(p3, pixel_tab, nb_pixels);
        pixel_point(p4, pixel_tab, nb_pixels);
        pixel_point(p5, pixel_tab, nb_pixels);
        pixel_point(p6, pixel_tab, nb_pixels);
        pixel_point(p7, pixel_tab, nb_pixels);
        pixel_point(p8, pixel_tab, nb_pixels);

        // fonctionnement du calcul de d, x et y grace à l'algorithme de tracé de cercle d'Andres
        if (d >= 2 * x) {
            d -= 2 * x + 1;
            x++;
        }
        else if (d <= (2 * (circle->radius - x))) {
            d += 2 * (y - 1);
            y--;
        }
        else {
            d += 2 * (y - x - 1);
            y--, x++;
        }
    }
}

void pixel_square(Square* square, Pixel*** pixel_tab, int* nb_pixels){

    // les coordonnées x et y des 4 points du carré
    int x1 = square->point->pos_x, y1 = square->point->pos_y;
    int x2 = x1 + square->lenght, y2 = y1;
    int x3 = x2, y3 = y1 + square->lenght;
    int x4 = x1, y4 = y3;

    // les 4 points, et 4 points bis pour pas redissiner les sommets
    Point* p1 = create_point(x1, y1);
    Point* p2 = create_point(x2, y2);

    Point* p2_bis = create_point(x2, (y2+1));
    Point* p3 = create_point(x3, y3);

    Point* p3_bis = create_point((x3-1), y3);
    Point* p4 = create_point(x4, y4);

    Point* p4_bis = create_point(x4, (y4-1));
    Point* p1_bis = create_point(x1, (y1+1));

    // les 4 lignes reliants les sommets
    Line* l1 = create_line(p1, p2);
    Line* l2 = create_line(p2_bis, p3);
    Line* l3 = create_line(p3_bis, p4);
    Line* l4 = create_line(p4_bis, p1);

    // on dessine les 4 lignes
    pixel_line(l1, pixel_tab, nb_pixels);
    pixel_line(l2, pixel_tab, nb_pixels);
    pixel_line(l3, pixel_tab, nb_pixels);
    pixel_line(l4, pixel_tab, nb_pixels);


}

void pixel_rectangle(Rectangle* rectangle, Pixel*** pixel_tab, int* nb_pixels){

    // les coordonnées x et y des 4 points du rectangle
    int x1 = rectangle->point->pos_x, y1 = rectangle->point->pos_y;
    int x2 = rectangle->point->pos_x + rectangle->width, y2 = rectangle->point->pos_y;
    int x3 = rectangle->point->pos_x + rectangle->width, y3 = rectangle->point->pos_y + rectangle->height;
    int x4 = rectangle->point->pos_x, y4 = rectangle->point->pos_y + rectangle->height;

    // les 4 points, et 4 points bis pour pas redissiner les sommets
    Point* p1 = create_point(x1, y1);
    Point* p2 = create_point(x2, y2);

    Point* p2_bis = create_point(x2, (y2+1));
    Point* p3 = create_point(x3, y3);

    Point* p3_bis = create_point((x3-1), y3);
    Point* p4 = create_point(x4, y4);

    Point* p4_bis = create_point(x4, (y4-1));
    Point* p1_bis = create_point(x1, (y1+1));

    // les 4 lignes reliants les sommets
    Line* l1 = create_line(p1, p2);
    Line* l2 = create_line(p2_bis, p3);
    Line* l3 = create_line(p3_bis, p4);
    Line* l4 = create_line(p4_bis, p1);

    // on dessine les 4 lignes
    pixel_line(l1, pixel_tab, nb_pixels);
    pixel_line(l2, pixel_tab, nb_pixels);
    pixel_line(l3, pixel_tab, nb_pixels);
    pixel_line(l4, pixel_tab, nb_pixels);

}

void pixel_polygon(Polygon* polygon, Pixel*** pixel_tab, int* nb_pixels){

    // on parcourt chaque point sauf le dernier
    for (int i = 0; i < (polygon->n)-1; i++){

        // on relie chaque point au suivant
        Point* p1 = create_point( polygon->points[i]->pos_x, polygon->points[i]->pos_y);
        Point* p2 = create_point( polygon->points[i+1]->pos_x, polygon->points[i+1]->pos_y);

        Line* l = create_line(p1, p2);

        pixel_line(l, pixel_tab, nb_pixels);
    }

}
