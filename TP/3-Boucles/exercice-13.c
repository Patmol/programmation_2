#include <stdio.h>
#include <math.h>

int main(void) {
    int x;
    float somme = 0;

    scanf("%d", &x);

    for(int i = 0; i <= x; i++) {
        somme += (1.0 / (pow(2, i)));
    }

    printf("%f.2\n", somme);

    return 0;
}