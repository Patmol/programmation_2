#include <stdio.h>

int array[20];

void affichageArray();

int main() {
    for (int i = 0; i < 20; i++) {
        array[i] = i * 10 - 4;
    }

    affichageArray();

    return 0;
}

void affichageArray() {
    for (int i = 0; i < 20; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}