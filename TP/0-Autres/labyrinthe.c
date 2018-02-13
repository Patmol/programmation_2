#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAILLE_LABY 20
#define NOMBRE_BONBONS 5

typedef struct position {
    int x;
    int y;
} Position;

typedef struct game {
    char labyrinthe[TAILLE_LABY][TAILLE_LABY];
    Position bonbons[NOMBRE_BONBONS];
    Position position;
    int points;
    bool fin;
} Game;

void remplissage(Game *game);
void affichage(Game *game);
void deplacement(Game *game, char deplacement);

int main(void) {
    Game *game;
    game = malloc(sizeof(Game));

    (*game).points = 0;
    (*game).fin = false;

    printf("Les déplacements se font avec 'z', 's', 'q', 'd'\n");
    
    remplissage(game);
    affichage(game);

    char mouvement = 'x';

    do {
        scanf("%c", &mouvement);
        deplacement(game, mouvement);
        affichage(game);

    } while (mouvement != 'x' && !(*game).fin);

    free(game);

    printf("Fin du jeu avec %d points!\n", (*game).points);

    return 0;
}

void remplissage(Game *game) {
    char item = ' ';

    // Generation des murs et des points
    for (int i = 0; i < TAILLE_LABY; i++) {
        for (int j = 0; j < TAILLE_LABY; j++) {
            if (i == 0 || i == TAILLE_LABY - 1 || j == 0 || j == TAILLE_LABY - 1) {
                item = '#';
            } else if(i == TAILLE_LABY / 2 && j == TAILLE_LABY / 2) {
                (*game).position.x = TAILLE_LABY / 2;
                (*game).position.y = TAILLE_LABY / 2;
            } else {
                item = '.';
            }

            (*game).labyrinthe[i][j] = item;
        }
    }

    // Generation des positions des bonbons
    srand(time(NULL));

    for (int i = 0; i < NOMBRE_BONBONS; i++) {
        (*game).bonbons[i].x = (rand() % (TAILLE_LABY - 2)) + 1;
        (*game).bonbons[i].y = (rand() % (TAILLE_LABY - 2))+ 1;
    }
}

void affichage(Game *game) {
    bool affichageBonbon = false;

    printf("Points: %d\n", (*game).points);

    for (int i = 0; i < TAILLE_LABY; i++) {
        for (int j = 0; j < TAILLE_LABY; j++) {
            // Affichage des bonbons
            if ((*game).position.x == i && (*game).position.y == j) {
                printf("x ");
            } else {
                for (int k = 0; k < NOMBRE_BONBONS && !affichageBonbon; k++) {
                    if ((*game).bonbons[k].x != 0 &&
                        (*game).bonbons[k].y != 0 && 
                        i == (*game).bonbons[k].x && 
                        j == (*game).bonbons[k].y) {
                        printf("$ ");
                        affichageBonbon = true;
                    }
                }

                if (!affichageBonbon) {
                    printf("%c ", (*game).labyrinthe[i][j]);
                }
            }

            affichageBonbon = false;
        }

        printf("\n");
    }
}

void deplacement(Game *game, char deplacement) {
    switch (deplacement) {
        case 'z':
            if((*game).position.x != 1)
                (*game).position.x--;
            break;
        case 's':
            if((*game).position.x != TAILLE_LABY - 2)
                (*game).position.x++;
            break;
        case 'q':
            if((*game).position.y != 1)
                (*game).position.y--;
            break;
        case 'd':
            if((*game).position.y != TAILLE_LABY - 2)
                (*game).position.y++;
            break;

    }

    // A chaque mouvement, le joueur perd un point
    (*game).points--;

    (*game).fin = true;

    // Verification si on est sur un bonbon
    for(int i = 0; i < NOMBRE_BONBONS; i++) {
        if ((*game).bonbons[i].x == (*game).position.x && (*game).bonbons[i].y == (*game).position.y) {
            (*game).bonbons[i].x = 0;
            (*game).bonbons[i].y = 0;
            (*game).points += 100;
        }

        if ((*game).bonbons[i].x != 0 && (*game).bonbons[i].y != 0) {
            (*game).fin = false;
        }
    }
}