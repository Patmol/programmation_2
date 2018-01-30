#include <stdio.h>

int main(void) {
    int n1, n2, lettre;
    float q, l;

    printf("Veuillez entrer deux nombres entiers: ");
    scanf("%d %d", &n1, &n2);

    printf("Quotien: %d\n", n1 % n2);
    q = ((float)n1 / n2) - (n1 / n2);
    printf("Fraction: %f\n", q);
    
    printf("Veuillez entrer un nombre réel: ");
    scanf("%f", &l);

    lettre = (int)(q * l) % 256;
    printf("Lettre: %c\n", lettre);

    return 0;
}