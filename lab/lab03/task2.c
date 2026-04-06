/* Задание 2: Использование calloc */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int i;

    printf("========== Задание 2: Использование calloc ==========\n");

    printf("Введите размер массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ошибка: размер должен быть положительным\n");
        return 1;
    }

    arr = (int*)calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Ошибка: не удалось выделить память\n");
        return 1;
    }

    printf("\n========== Значения после calloc (инициализированы нулями) ==========\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\nВведите %d элементов:\n", n);
    for (i = 0; i < n; i++) {
        printf("Элемент [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n========== Обновленный массив ==========\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}
