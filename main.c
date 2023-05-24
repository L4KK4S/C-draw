#include <stdio.h>
#include "Id.h"
#include "Area.h"
#include "Command.h"



int main() {

    // on initialise une area, et la variable de la boucle du preogramme
    Area* area = create_area(25, 25);
    int run = 1;
    printf("Bienvenue sur C-Draw!\n\nTapez 'help' si vous avez besoin d'aide");

    // tant que run on fait tourner le programme
    while (run){

        printf("\n>>");
        Command* cmd = create_command(); // on crée un commande
        read_from_stdin(cmd); // on récupère le nom de la commande et le contenu des paramètres
        if (read_exec_command(cmd, area)){ // on execute la commande, si ca retourne 0 ca veut dire que la commande est 'exit' donc on arrete la boucle du programme
            run = 0;
        }

    }

    return 0;
}