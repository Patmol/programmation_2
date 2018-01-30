#include <stdio.h>
#include <math.h>

int main(void) {
    int a, b, c, delta;

    scanf("%d %d %d", &a, &b, &c);

    delta = (b * b) - (4 * a * c);

    if (delta < 0) {
        printf("Pas de solution\n");
    } else if (delta == 0) {
        printf("Solution: %f\n", (-b / (2.0 * a)));
    } else {
        printf("Solution 1: %f\n", (((-b) - sqrt(delta)) - (2 * a)));
        printf("Solution 2: %f\n", (((-b) + sqrt(delta)) - (2 * a)));
    }

    return 0;
}