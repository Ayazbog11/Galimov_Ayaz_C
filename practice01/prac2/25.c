#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Введите N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) sum += i;
    }
    printf("Сумма делителей: %d\n", sum);
    return 0;
}
