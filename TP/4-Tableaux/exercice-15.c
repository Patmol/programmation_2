#include <stdio.h>
#include <math.h>

#define MAX_I 31

int main(void) {
    int tab[MAX_I];

    for(float i = 0; i <= MAX_I; i++) {
        tab[(int)i] = pow(2.0, i);
    }

    return 0;
}