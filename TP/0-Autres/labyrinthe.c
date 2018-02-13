#include <stdio.h>

#define TAILLE_LABY 50

void remplissage(char labyrinthe[TAILLE_LABY][TAILLE_LABY]);
void affichage(char labyrinthe[TAILLE_LABY][TAILLE_LABY]);

int main(void) {
    char labyrinthe[TAILLE_LABY][TAILLE_LABY];

    remplissage(labyrinthe);
    affichage(labyrinthe);

    return 0;
}

void remplissage(char labyrinthe[TAILLE_LABY][TAILLE_LABY]) {
    char item = ' ';

    for (int i = 0; i < TAILLE_LABY; i++) {
        for (int j = 0; j < TAILLE_LABY; j++) {
            if (i == 0 || i == TAILLE_LABY - 1 || j == 0 || j == TAILLE_LABY - 1) {
                item = '#';
            } else if(i == TAILLE_LABY / 2 && j == TAILLE_LABY / 2) {
                item = 'X';
            } else {
                item = '.';
            }

            labyrinthe[i][j] = item;
        }
    }
}

void affichage(char labyrinthe[TAILLE_LABY][TAILLE_LABY]) {
    for (int i = 0; i < TAILLE_LABY; i++) {
        for (int j = 0; j < TAILLE_LABY; j++) {
            printf("%c ", labyrinthe[i][j]);
        }

        printf("\n");
    }
}