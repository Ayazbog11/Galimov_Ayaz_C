#include <stdio.h>

int main() {
    printf("+--------------+\n");
    printf("|  ТАБЛИЦА     |\n");
    printf("+--------------+\n");

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i * j > 50) continue;
            printf("| %2d * %-2d = %2d |\n", i, j, i * j);
        }
        printf("+--------------+\n");
    }

    return 0;
}
