#include <stdlib.h>
#include <stdio.h>
#include "Point.h"
#include "Line.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Shape.h"
#include "Id.h"

// Shape fonctions ------------------------------------------------------------------------------

Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py){
    Shape *temp_shape = create_empty_shape(POINT);
    Point *temp_point = create_point(px, py);
    temp_shape->ptrShape = temp_point;

    return temp_shape;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *temp_shape = create_empty_shape(LINE);
    Point *temp_point_1 = create_point(px1,py1);
    Point *temp_point_2 = create_point(px2,py2);
    Line *temp_line = create_line(temp_point_1,temp_point_2);
    temp_shape->ptrShape = temp_line;

    return temp_shape;
}

Shape *create_square_shape(int px, int py, int length){
    Shape *temp_shape = create_empty_shape(SQUARE);
    Point *temp_point = create_point(px,py);
    Square *temp_square = create_square(temp_point,length);
    temp_shape->ptrShape = temp_square;

    return temp_shape;
}

Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *temp_shape = create_empty_shape(RECTANGLE);
    Point *temp_point = create_point(px,py);
    Rectangle *temp_rectangle = create_rectangle(temp_point, width, height);
    temp_shape->ptrShape = temp_rectangle;

    return temp_shape;
}

Shape *create_circle_shape(int px, int py, int radus){
    Shape *temp_shape = create_empty_shape(CIRCLE);
    Point *temp_point= create_point(px,py);
    Circle *temp_circle= create_circle(temp_point,radus);
    temp_shape->ptrShape=temp_circle;

    return temp_shape;
}

Shape *create_polygon_shape(int lst[], int n){
    Shape *temp_shape = create_empty_shape(POLYGON);
    Point** tab = (Point**) malloc(sizeof (Point*) * n/2);
    int j = 0;
    for (int i = 0; i < n; i +=2){
        Point* p1 = create_point(lst[i], lst[i+1]);
        tab[j] = p1;
        j ++;
    }
    Polygon *temp_polygon = create_polygon(n/2, tab);
    temp_shape->ptrShape = temp_polygon;

    return temp_shape;
}

void delete_shape(Shape * shape){

    switch (shape->shape_type) {

        case POINT:
            delete_point(shape->ptrShape); break;

        case LINE:
            delete_line(shape->ptrShape); break;

        case SQUARE:
            delete_square(shape->ptrShape); break;

        case RECTANGLE:
            delete_rectangle(shape->ptrShape); break;

        case CIRCLE:
            delete_circle(shape->ptrShape); break;

        case POLYGON:
            delete_polygon(shape->ptrShape); break;

        default:
            printf("Unknown shape type");

    }
    free(shape);

}

void print_shape(Shape * shape){

    switch (shape->shape_type) {

        case POINT:
            print_point(shape->ptrShape); break;

        case LINE:
            print_line(shape->ptrShape); break;

        case SQUARE:
            print_square(shape->ptrShape); break;

        case RECTANGLE:
            print_rectangle(shape->ptrShape); break;

        case CIRCLE:
            print_circle(shape->ptrShape); break;

        case POLYGON:
            print_polygon(shape->ptrShape); break;

        default:
            printf("Unknown shape type");

    }

}
// ----------------------------------------------------------------------------------------------


