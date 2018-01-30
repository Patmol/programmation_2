#include <stdio.h>

int main(void) {
    int number;

    scanf("%d", &number);

    printf("Dizaine: %d\n", (number - (number / 100 * 100)) / 10 );
    printf("Centaine: %d\n", number / 100);
}