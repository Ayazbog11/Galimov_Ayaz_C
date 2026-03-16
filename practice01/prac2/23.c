#include <stdio.h>

int main() {
    int n, count = 0;
    printf("Введите N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) count++;
    }
    printf("Количество делителей: %d\n", count);
    return 0;
}
