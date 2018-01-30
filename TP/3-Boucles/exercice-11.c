#include <stdio.h>

int main(void) {
    int x;

    scanf("%d", &x);

    for (int i = 1; i <= x; i++) {
        printf("%d ", 2 * i);
    }
    printf("\n");

    for (int i = 1; i <= x; i++) {
        printf("%f ", 1.0 / i);
    }
    printf("\n");

    for (int i = 1; i <= x; i++) {
        printf("%d ", i * i);
    }
    printf("\n");

    for (int i = 1; i <= x; i++) {
        printf("%f ", (i * (i - 1.0)) / i);
    }
    printf("\n");

    return 0;
}