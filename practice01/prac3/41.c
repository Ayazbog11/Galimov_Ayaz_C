#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Введите N: ");
    scanf("%d", &n);

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    printf("Сумма цифр: %d\n", sum);
    return 0;
}
