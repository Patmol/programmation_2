#include <stdio.h>

#define MAX 500

int main(void) {
    int tab[MAX];
    int valeurI;
    
    // Intialisation
    for(int i = 0; i < MAX; i++) {
        tab[i] = i + 2;
    }

    // Crible d’Eratosthène
    for(int i = 0; i < MAX; i++) {
        valeurI = tab[i];

        if (valeurI != 0) {
            for (int j = i; j < MAX; j++) {
                if (tab[j] != 0 && tab[j] != valeurI && tab[j] % valeurI == 0) {
                    tab[j] = 0;
                }
            }
        }
    }

    // Affichage
    for(int i = 0; i < MAX; i++) {
        if (tab[i] != 0) {
            printf("%d ", tab[i]);
        }
    }

    printf("\n");

    return 0;
}