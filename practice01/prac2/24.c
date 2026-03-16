#include <stdio.h>

int main() {
    int n, is_prime = 1;
    printf("Введите N: ");
    scanf("%d", &n);

    if (n < 2) is_prime = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            is_prime = 0;
            break;
        }
    }
    printf(is_prime ? "Число простое\n" : "Число не является простым\n");
    return 0;
}
