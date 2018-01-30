#include <stdio.h>
#include <math.h>

int main(void) {
    int x;

    scanf("%d", &x);

    for(int i = 0; i <= x; i++) {
        printf("%.2f ", (1.0 / pow(2, i)));
    }

    printf("\n");

    return 0;
}