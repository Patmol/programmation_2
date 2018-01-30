#include <stdio.h>

int fibonacci(int n);

int main(void) {
    printf("%d\n", fibonacci(7));
    printf("%d\n", fibonacci(10));

    return 1;
}

int fibonacci(int n) {
    if (n <= 1){
        return n;
    }
 
    int fibo = 1;
    int fiboPrev = 1;
 
    for (int i = 2; i < n; ++i) {
        int temp = fibo;
        fibo += fiboPrev;
        fiboPrev = temp;
    }
    
    return fibo;
}