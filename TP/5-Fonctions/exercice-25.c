#include <stdio.h>

int factorielle(int n);

int main() {
    printf("%d\n", factorielle(7));
    printf("%d\n", factorielle(10));

    return 0;
}

int factorielle(int n) {
    int c;
    long result = 1;
 
    for (c = 1; c <= n; c++) { 
        result = result * c;
    }
    
    return result;
}