#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Command.h"
#include "Shape.h"
#include "Id.h"


Command* create_command(){
    Command* cmd = (Command*) malloc(sizeof (Command));
    cmd->int_size = 0;
    cmd->str_size = 0;
    return cmd;
}

void add_str_param(Command* cmd, char* p){
    cmd->str_params[cmd->str_size] = p;
    cmd->str_size++;
}

void add_int_param(Command* cmd, int p){
    cmd->int_params[cmd->int_size] = p;
    cmd->int_size++;
}

void free_cmd(Command* cmd){
    free(cmd->str_params);
    free(cmd);
}

int read_exec_command(Command* cmd, Area* area){

    // on utilise la fonction strcmp pour comparer deux chaines de caractère et voir le nombre de caractères différents, si c'est 0 elels sont égales

    if (strcmp(cmd->name, "help") == 0) {
        printf("- clear : efface l'ecran\n"
               "- exit : quitte le programme\n"
               "- point x y : ajoute un point de coordonne (x;y)\n"
               "- line x1 y1 x2 y2 : ajoute un segment reliant les deux points (x1, y1) et (x2, y2)\n"
               "- circle x y radius : ajoute un cercle de centre (x, y) et de rayon radius\n"
               "- square x y length : ajoute un carre dont le coin superieur gauche est (x, y) et de cote length.\n"
               "- rectangle x y width height : ajoute un rectangle dont le coin superieur gauche est (x, y), de largeur width et de longueur height\n"
               "- polygon x1 y1 x2 y2 x3 y3 ... ... : ajoute un polygone avec la liste des points donnes\n"
               "- plot : rafraichis l'ecran pour afficher toutes les formes geometriques de l'image\n"
               "- list : affiche la liste de l'ensemble des formes geometriques qui composent l'image ainsi que toutes leurs informations\n"
               "- delete id : supprime une forme a partir de son identifiant id\n"
               "- erase : supprime toutes les formes d'une image\n"
               "- help : afficher la liste des commandes ainsi qu un mini-mode d emploi permettant à l'utilisateur d'utiliser les commandes correctement\n");
    }

    else if (strcmp(cmd->name, "plot") == 0) {
        draw_area(area);
        print_area(area);
    }

    else if (strcmp(cmd->name, "erase") == 0) {
        erase_area(area);
        clear_area(area);
    }

    else if (strcmp(cmd->name, "clear") == 0) {
        system("cls");
    }

    else if (strcmp(cmd->name, "point") == 0) {

        if (cmd->int_size == 2){
            Shape *temp_shape = create_point_shape(cmd->int_params[0], cmd->int_params[1]);
            add_shape_to_area(area, temp_shape);
        }
        else {
            printf("Erreur: Nombre de parametres incorrect - la fonction square prend en parametre 2 entiers\n");
        }
    }

    else if (strcmp(cmd->name, "line") == 0) {

        if (cmd->int_size == 4){
            Shape *temp_shape = create_line_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3]);
            add_shape_to_area(area, temp_shape);
        }
        else {
            printf("Erreur: Nombre de parametres incorrect - la fonction line prend en parametre 4 entiers\n");
        }
    }

    else if (strcmp(cmd->name, "square") == 0) {

        if (cmd->int_size == 3){
            Shape *temp_shape = create_square_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2]);
            add_shape_to_area(area, temp_shape);
        }
        else {
            printf("Erreur: Nombre de parametres incorrect - la fonction square prend en parametre 3 entiers\n");
        }
    }

    else if (strcmp(cmd->name, "rectangle") == 0) {

        if (cmd->int_size == 4){
            Shape *temp_shape = create_rectangle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3]);
            add_shape_to_area(area, temp_shape);
        }
        else {
            printf("Erreur: Nombre de parametres incorrect - la fonction rectangle prend en parametre 4 entiers\n");
        }
    }

    else if (strcmp(cmd->name, "circle") == 0) {

        if (cmd->int_size == 3){
            Shape *temp_shape = create_circle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2]);
            add_shape_to_area(area, temp_shape);
        }
        else {
            printf("Erreur: Nombre de parametres incorrect - la fonction circle prend en parametre 3 entiers\n");
        }
    }

    else if (strcmp(cmd->name, "polygon") == 0) {

        if (!(cmd->int_size % 2)){
            int polygon_points[cmd->int_size];
            for (int i = 0; i < cmd->int_size; i++){
                polygon_points[i] = cmd->int_params[i];
            }
            Shape *temp_shape = create_polygon_shape(polygon_points, cmd->int_size);
            add_shape_to_area(area, temp_shape);
        }
        else {
            printf("Erreur: Nombre de parametres incorrect - la fonction polygon prend en parametre un nombre pair de parametre\n");
        }
    }

    else if (strcmp(cmd->name, "list") == 0) {

        int id_indexes[area->nb_shape];
        int same_id , nb_id = 0;

        if (!area->nb_shape){
            printf("Aucune forme n'a encore etee cree\n");
        }

        for (int i = 0; i < area->nb_shape; i++){

            switch (area->shapes[i]->shape_type) {

                case POINT: {
                    print_point(area->shapes[i]->ptrShape);
                    printf(" | id: %d\n", area->shapes[i]->id);
                    break;
                }
                case LINE: {
                    print_line(area->shapes[i]->ptrShape);
                    printf(" | id: %d\n", area->shapes[i]->id);
                    break;
                }
                case SQUARE: {
                    print_square(area->shapes[i]->ptrShape);
                    printf(" | id: %d\n", area->shapes[i]->id);
                    break;
                }
                case RECTANGLE: {
                    print_rectangle(area->shapes[i]->ptrShape);
                    printf(" | id: %d\n", area->shapes[i]->id);
                    break;
                }
                case CIRCLE: {
                    print_circle(area->shapes[i]->ptrShape);
                    printf(" | id: %d\n", area->shapes[i]->id);
                    break;
                }
                case POLYGON: {
                    print_polygon(area->shapes[i]->ptrShape);
                    printf(" | id: %d\n", area->shapes[i]->id);
                    break;
                }
                default: {
                    ;
                }

            }

        }

    }

    else if (strcmp(cmd->name, "delete") == 0) {

        // on supprime la shape et on decale toutes les shapes de droite à gauche pour combler le trou (mais problème d'affichage de 'list')

        if (cmd->int_size == 1){
            for (int i = 0; i < area->nb_shape; i++){
                if (area->shapes[i]->id == cmd->int_params[0]){
                    for (int j = i; j < area->nb_shape-1; j++){
                        area->shapes[j] = area->shapes[j+1];
                    }
                    area->nb_shape--;
                }
            }
            clear_area(area);
            int nb = area->nb_shape-1;
            for (int i = 0; i < nb; i++){
                add_shape_to_area(area, area->shapes[i]);
            }
        }

        else {
            printf("Erreur: Nombre de parametres incorrect - la fonction delete  prend en parametre un entier\n");
        }
    }

    else if (strcmp(cmd->name, "exit") == 0) {
        printf("\nMerci d'avoir utilise C-Draw, a la prochaine!");
        return 1;
    }

    else {
        printf("Erreur: Commande incorrecte - cette comande n'existe pas ou a etee mal ecrite\n");
    }


    return  0;

}


void read_from_stdin(Command* cmd) {

    char line[50];
    fgets(line, sizeof(line), stdin); // on recupère le input

    char* token = strtok(line, " \n"); // on crée un 'token', qui est le premier mot donc la commande
    if (token != NULL) { // si celui-ci n'est pas == NULL donc que le mot ne soit pas vide
        strcpy(cmd->name, token); // on met celui-ci dans name

        token = strtok(NULL, " \n"); // on recupère le 'token' suivant
        while (token != NULL) { // tant qu'il y a un mot après
            if (atoi(token) != 0 || strcmp(token, "0") == 0 ) { // si c'est un int ou 0 on le met dans int_param
                int param = atoi(token);
                add_int_param(cmd, param);
            } else { // sinon dans str_param
                add_str_param(cmd, token);
            }
            token = strtok(NULL, " \n"); // on recupère le 'token' suivant
        }
    }

}
