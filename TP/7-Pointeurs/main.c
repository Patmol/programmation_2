#include <stdio.h>
#include <stdbool.h>

#include "listeC.h"

int main(void) {
    int choix;
    bool end = false;

    node* liste = NULL;

    do {
        choix = menu();

        switch(choix) {
            case 1:
                liste = creer(liste);
                break;
            case 2:
                liste = supprimer(liste);
                break;
            case 3:
                montrer(liste);
                break;
            case 4:
                end = true;
                break;
        }
    } while(!end);
    
    return 0;
}