#include <stdio.h>

int main() {
    long long n, nd;
    printf("Введите N: ");
    scanf("%lld", &n);

    if (n == 0) {
        return 0;
    }

    for (int i = 0; i <= 9; i++) {
        int count = 0;
        nd = n;

        while (nd > 0) {
            if (nd % 10 == i) {
                count++;
            }
            nd /= 10;
        }

        if (count > 0) {
            printf("Цифра %d: %d раз\n", i, count);
        }
    }

    return 0;
}
