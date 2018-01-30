#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));

    int tab[50];
    int max;

    scanf("%d", &max);

    for(int i = 0; i < 50; i++) {
        tab[i] = (rand() % max) + 1;
    }

    return 0;
}