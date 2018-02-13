#include <stdio.h>

int main(void) {
    int nombre;

    FILE *file;

    file = fopen("nombre.txt", "r");

    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier");
    } else {
        fscanf(file, "%d", &nombre);
        while(!feof(file)) {
            printf("%d * %d = %d\n", nombre, nombre, nombre * nombre);
            fscanf(file, "%d", &nombre);
        }
    }

    fclose(file);
    printf("\n");
}