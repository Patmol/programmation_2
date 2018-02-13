#include <stdio.h>
#include <string.h>

int main(void) {
    char chaine1[50];
    char chaine2[50];

    printf("Chaine 1: ");
    scanf("%s", chaine1);
    printf("Chaine 2: ");
    scanf("%s", chaine2);

    char *resultCat = strcat(chaine1, chaine2);
    printf("strcat\n");
    printf("Chaine 1: %s\n", chaine1);
    printf("Chaine 2: %s\n", chaine2);
    printf("Result: %s\n", resultCat);

    int resultCmp = strcmp(chaine1, chaine2);
    printf("strcmp\n");
    printf("Chaine1: %d\n", resultCmp);

    char *resultCpy = strcpy(chaine1, chaine2);
    printf("strcpy\n");
    printf("Chaine 1: %s\n", chaine1);
    printf("Chaine 2: %s\n", chaine2);
    printf("Result: %s\n", resultCpy);
}