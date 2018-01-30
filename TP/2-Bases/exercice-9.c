#include <stdio.h>

int main(void) {
    int x;

    scanf("%d", &x);

    if (x >= 0) {
        printf("positif\n");
    } else {
        printf("negatif\n");
    }

    if (x % 2 == 0) {
        printf("pair\n");
    } else {
        printf("impair\n");
    }

    return 0;
}