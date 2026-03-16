#include <stdio.h>

int main() {
    int n;
    unsigned long long fact = 1;
    printf("Введите N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) fact *= i;
    }
    printf("Произведение нечётных чисел до %d: %llu\n", n, fact);
    return 0;
}
