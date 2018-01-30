#include <stdio.h>

int fibonacci(int n);

int main(void) {
    printf("%d\n", fibonacci(7));
    printf("%d\n", fibonacci(10));

    return 1;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
     } 
     if (n == 1) {
        return 1;
     }
     return fibonacci(n - 1) + fibonacci(n - 2);
}