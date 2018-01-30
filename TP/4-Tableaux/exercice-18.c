#include <stdio.h>

#define TAB_SIZE 50

int main(void) {
    srand(time(NULL));

    int array[TAB_SIZE];
    int indexDebutSuite = 0;
    int previousNumber = -1;
    int longueur = 1;

    for(int i = 0; i < TAB_SIZE; i++) {
        array[i] = rand() % 100;
    }

    for(int i = 0; i < TAB_SIZE; i++) {
        if (array[i] > previousNumber) {
            previousNumber = array[i];
            longueur++;
        } else {
            printf("Index début: %d\n", indexDebutSuite);
            printf("Index fin: %d\n", i - 1);
            printf("Longueur suite: %d\n", longueur);
            indexDebutSuite = i;
            longueur = 0;
            previousNumber = array[i];
        }
    } 

    return 0;
} 