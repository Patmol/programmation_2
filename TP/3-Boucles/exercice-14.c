#include <stdio.h>

int main(void) {
    float u = 1, v;

    for (int n = 1; u > 0.001; n++) {
        u = (1.0 / (n * n));
        v = 0;

        for (int k = 1; k < n; k++) {
            v += (1.0 / (k * k));
        }

        printf("%3d %f %f\n", n, u, v);
    }

    return 0;
}