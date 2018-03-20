#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listeC.h"

int menu() {
    int choix;

    printf("1 -> Ajouter un élément à la liste.\n");
    printf("2 -> Supprimer un élément à la liste.\n");
    printf("3 -> Afficher la liste.\n");
    printf("4 -> Quitter.\n");
    printf("Choix: ");
    scanf("%d", &choix);

    return choix;
}
void* creer(void * liste) {
    int data;
    node *new, *ptr;

    printf("Veuillez entrer votre valeur à ajouter: ");
    scanf("%d", &data);

    if (liste != NULL) {
        ptr = liste;
        while (ptr->nextptr != NULL) {
            ptr = ptr->nextptr; 
        }

        new = malloc(sizeof(node));
        new->data = data;
        new->nextptr = NULL;
        ptr->nextptr = new;
    } else {
        new = malloc(sizeof(node));
        new->data = data;
        new->nextptr = NULL;
        liste = new;
    }

    return liste;
}

void* supprimer(void * liste) {
    int data;
    node *ptr, *prevptr = NULL;

    printf("Veuillez entrer votre valeur à supprimer: ");
    scanf("%d", &data);

    ptr = liste;

    while (ptr != NULL && ptr->data != data) {
        prevptr = ptr;
        ptr = ptr->nextptr;
    }

    if (ptr != NULL && ptr->data == data) { 
        if (prevptr == NULL) {
            liste = ptr->nextptr;
        }
        else {
            prevptr->nextptr = ptr->nextptr;
        }
        free(ptr);
    }

    return liste;
}

void montrer(void * liste) {
    if (liste == NULL) {
        return;
    }

    node *ptr = liste;

    do {
        printf("%d ", ptr->data);
        ptr = ptr->nextptr;
    } while(ptr != NULL);

    printf("\n");
}