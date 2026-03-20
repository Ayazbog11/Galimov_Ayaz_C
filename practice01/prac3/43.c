#include <stdio.h>

int main() {
    int n, max_d = 0;
    printf("Введите N: ");
    scanf("%d", &n);

    while (n > 0) {
        int d = n % 10;
        if (d > max_d) max_d = d;
        n /= 10;
    }

    printf("Макс. цифра: %d\n", max_d);
    return 0;
}
