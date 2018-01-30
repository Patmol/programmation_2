#include <stdio.h>
#include <math.h>

int main(void) {
    int x, somme;

    scanf("%d", &x);

    for(int i = 0; i <= x; i++) {
        somme += (1.0 / pow(2, i));
    }

    printf("%d\n", somme);

    return 0;
}