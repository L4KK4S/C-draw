cmake_minimum_required(VERSION 3.24)
project(drawy C)

set(CMAKE_C_STANDARD 23)

add_executable(drawy main.c Point.c Point.h Line.c Line.h Square.c Square.h Rectangle.c Rectangle.h Circle.c Circle.h Polygon.c Polygon.h Shape.c Shape.h Id.c Id.h Area.c Area.h Pixel.c Pixel.h Command.c Command.h)
