/* Задание 6: Вставка элемента */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int *tmp;
    int index;
    int value;
    int i;

    printf("========== Задание 6: Вставка элемента ==========\n");

    printf("Введите размер массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ошибка: размер должен быть положительным\n");
        return 1;
    }

    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    printf("Введите %d элементов:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n========== Исходный массив ==========\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nВведите позицию для вставки (0-%d): ", n);
    scanf("%d", &index);

    if (index < 0 || index > n) {
        printf("Ошибка: неверная позиция\n");
        free(arr);
        return 1;
    }

    printf("Введите значение для вставки: ");
    scanf("%d", &value);

    n++;
    tmp = (int*)realloc(arr, n * sizeof(int));

    if (tmp == NULL) {
        printf("Ошибка: не удалось увеличить массив\n");
        free(arr);
        return 1;
    }

    arr = tmp;

    for (i = n - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;

    printf("\n========== Массив после вставки ==========\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}
