#include <stdio.h>
int main() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i * j > 30) continue;
            printf("%d*%d=%-2d\t", i, j, i * j);
        }
        printf("\n");
    }
    return 0;
}
