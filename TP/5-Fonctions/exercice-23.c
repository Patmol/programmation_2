#include <stdio.h>

int factorielle(int n);

int main() {
    printf("%d\n", factorielle(7));
    printf("%d\n", factorielle(10));

    return 0;
}

int factorielle(int n) {
    return n == 0 ? 1 : n * factorielle(n - 1);
    
    /*
    if (n == 0) {
        return 1;
    }

    return n * factorielle(n - 1);
    */
}