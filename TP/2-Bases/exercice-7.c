#include <stdio.h>

int main(void) {
    int x, y;

    scanf("%d", &x);
    scanf("%d", &y);

    if ((x >= 0 && y >= 0) || (x < 0 && y < 0)) {
        printf("VRAI\n");
    } else {
        printf("FAUX\n");
    }

    return 0;
}