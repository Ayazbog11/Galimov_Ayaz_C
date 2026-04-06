#include <stdio.h>

int main() {
    int n, x, count = 0;

    printf("Размер массива: ");
    scanf("%d", &n);

    int mas[n];
    int *ptr = mas;

    printf("Введите элементы: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", (ptr + i));
    }

    printf("Введите число X: ");
    scanf("%d", &x);

    int *p = mas; 
    for (int i = 0; i < n; i++) {
        if (*p > x) { 
            count++;
        }
        p++; 
    }

    printf("Количество элементов > %d: %d\n", x, count);

    return 0;
}
