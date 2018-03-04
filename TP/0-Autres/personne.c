#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct personne {
    char *nom;
    char *prenom;
    struct personne *pere;
    struct personne *mere;
} Personne;

int main() {
    Personne *jules;
    Personne *jacques;
    Personne berthe;

    jules = (Personne*)malloc(sizeof(Personne));
    jacques = (Personne*)malloc(sizeof(Personne));

    return 0;
}