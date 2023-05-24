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

Area* create_area(unsigned int width, unsigned int height) {

    // on crée l'espace nécessaire à une area
    Area* temp_area = (Area*)malloc(sizeof(Area));

    // on lui associe son height, son width et son nb_shape à 0
    temp_area->width = width;
    temp_area->height = height;

    temp_area->nb_shape = 0;

    // on crée l'espace nécessaire à un tableau 2D de la taille de width * height

    // on crée l'espace pour les lignes
    temp_area->mat = (BOOL **) malloc(sizeof(BOOL *) * height);

    for (int i = 0; i < height; i++) {
        temp_area->mat[i] = calloc(width, sizeof(BOOL));
    }




    // on retourne l'area
    return temp_area;

}

void add_shape_to_area(Area* area, Shape* shape){
    // on assigne à la premiere place vide la shape et on incremente le nb_shape
    area->shapes[area->nb_shape] = shape;
    area->nb_shape++;

}

void clear_area(Area* area){

    // on met toutes les valeurs des pixels à 0
    for (int i = 0; i < area->height; i++){
        for (int j = 0; j < area->width; j++)
            area->mat[i][j] = 0;
    }

}

void erase_area(Area* area){

    // on parcours le tableau de shape, à chaque fois que l'on en trouve une, on libère la mémoire et on réintialise son pointeur à NULL
    for (int i = 0; i < area->nb_shape; i++) {
        if (area->shapes[i] != NULL){
            delete_shape(area->shapes[i]);
        }
    }
    // on réinitialise le nb_shape à 0
    area->nb_shape = 0;

}

void delete_area(Area* area) {

    // on supprime les formes
    erase_area(area);
    // on supprime les pixels
    clear_area(area);
    // on supprime l'area
    free(area);

}


void draw_area(Area* area){

    // on parcourt chaque shape
    for(int w = 0; w < area->nb_shape; w++){

        // on crée un tableau de Pixel**
        Pixel*** pixel_tab = (Pixel***) malloc(sizeof(Pixel**));
        int nb_pixel = 0;

        // on récupère les pixels de chaque forme
        create_shape_to_pixel(area->shapes[w], pixel_tab, &nb_pixel);

        // on les met dans
        for (int i = 0; i < area->width; i++) {
            for (int j = 0; j < area->height; j++) {

                for (int k = 0; k < nb_pixel; k++) {
                    if ( (*pixel_tab)[k]->px == j && (*pixel_tab)[k]->py == i) {
                        ((*area).mat)[i][j] = 1;
                    }
                }

            }
        }

    }


}


void print_area(Area* area){

    // on parcourt la matrice et on affiche en fonction du résultat
    for (int i = 0; i < area->width; i++) {
        for (int j = 0; j < area->height; j++) {
            if (area->mat[i][j] == 1) {
                printf("@ ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }

}



Pixel*** create_shape_to_pixel(Shape * shape, Pixel*** pixel_tab, int* nb_pixels){

    // selon le shape_type ...
    switch (shape->shape_type) {

        // ... on converti en pixels la shape
        case POINT: {
            pixel_point(shape->ptrShape, pixel_tab, nb_pixels);
            break;
        }
        case LINE: {
            pixel_line(shape->ptrShape, pixel_tab, nb_pixels);
            break;
        }
        case SQUARE: {
            pixel_square(shape->ptrShape, pixel_tab, nb_pixels);
            break;
        }
        case RECTANGLE: {
            pixel_rectangle(shape->ptrShape, pixel_tab, nb_pixels);
            break;
        }
        case CIRCLE: {
            pixel_circle(shape->ptrShape, pixel_tab, nb_pixels);
            break;
        }
        case POLYGON: {
            pixel_polygon(shape->ptrShape, pixel_tab, nb_pixels);
            break;
        }
        default: {
            ;
        }

    }
    return pixel_tab;

}
