#include <stdio.h>

int main() {
    int n;

    printf("Введите число n для таблицы умножения: ");
    scanf("%d", &n);
    printf("\n=====================\n");
    printf("  Таблица умножения на %d\n", n);
    printf("=====================\n");
    for (int i = 1; i <= 10; i++) {
        printf("  %d x%3d = %3d\n", n, i, n * i);
    }
    printf("=====================\n");
    return 0;
}
