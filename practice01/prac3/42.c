#include <stdio.h>

int main() {
    int n;
    long long prod = 1;
    int has_digits = 0;
    printf("Введите N: ");
    scanf("%d", &n);

    if (n == 0) prod = 0;

    while (n > 0) {
        int d = n % 10;
        if (d != 0) {
            prod *= d;
            has_digits = 1;
        }
        n /= 10;
    }

    printf("Произведение: %lld\n", has_digits ? prod : 0);
    return 0;
}
