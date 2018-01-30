#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));
    int numberToFind = (rand() % 100) + 1;
    int number;

    do {
        scanf("%d", &number);
    } while (number != numberToFind);

    printf("Vous avez trouve!");

    return 0;
}