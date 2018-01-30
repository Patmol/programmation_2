#include <stdio.h>

void affichageArray(int array[]);

int main() {
    int array[20];
    
    for (int i = 0; i < 20; i++) {
        array[i] = i * 10 - 4;
    }

    affichageArray(array);

    return 0;
}

void affichageArray(int array[]) {
    for (int i = 0; i < 20; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}