#include <stdio.h>

int main(void) {
    char fileName[50];
    char line[50];

    printf("Filename: ");
    scanf("%s", fileName);

    FILE *file;

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
    } else {
        fscanf(file, "%s", line);
        while(!feof(file)) {
            printf("%s ", line);
            fscanf(file, "%s", line);
        }
    }

    fclose(file);
}