/* Задание 1: Создание динамического массива */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int i;

    printf("========== Задание 1: Динамический массив (malloc) ==========\n");

    printf("Введите размер массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ошибка: размер должен быть положительным\n");
        return 1;
    }

    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Ошибка: не удалось выделить память\n");
        return 1;
    }

    printf("Введите %d элементов:\n", n);
    for (i = 0; i < n; i++) {
        printf("Элемент [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n========== Введенный массив ==========\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;

    printf("\n========== Память освобождена ==========\n");

    return 0;
}