#include <stdio.h>

void affichageTableau(int array[]);
void changementSigne(int array[]);

int main() {
    int array[20];
    
    for (int i = 0; i < 20; i++) {
        array[i] = i * 10 - 4;
    }

    affichageTableau(array);
    changementSigne(array);
    affichageTableau(array);

    return 0;
}

void affichageTableau(int array[]) {
    for (int i = 0; i < 20; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void changementSigne(int array[]) {
    for (int i = 0; i < 20; i++) {
        array[i] *= -1;
    }
}