#include <stdio.h>
#include <stdlib.h>

struct ligneLabyrinthe {
    struct caseLabyrinthe *caseLabyrinthe;
    struct ligneLabyrinthe *next;
};

struct caseLabyrinthe {
    int data;
    struct caseLabyrinthe *next;
};

int main(void) {
    char *value;
    
    FILE *file;

    file = fopen("file-to-load.txt", "r");
    // Reading file
    if (file == NULL) {
        return 1;
    } else {
        fscanf(file, "%s", value);

        printf("%s\n", value);
    }
    return 0;
}