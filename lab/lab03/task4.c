/* Задание 4: Изменение размера массива (realloc) */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *arr;
    int *tmp;
    int i;

    printf("========== Задание 4: Изменение размера (realloc) ==========\n");

    printf("Введите начальный размер массива: ");
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

    printf("\n========== Текущий массив ==========\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nВведите новый размер массива (больше %d): ", n);
    scanf("%d", &m);

    if (m <= 0) {
        printf("Ошибка: размер должен быть положительным\n");
        free(arr);
        return 1;
    }

    tmp = (int*)realloc(arr, m * sizeof(int));

    if (tmp == NULL) {
        printf("Ошибка: не удалось изменить размер\n");
        free(arr);
        return 1;
    }

    arr = tmp;

    if (m > n) {
        printf("Введите %d новых элементов:\n", m - n);
        for (i = n; i < m; i++) {
            printf("Элемент [%d]: ", i);
            scanf("%d", &arr[i]);
        }
    }

    printf("\n========== Обновленный массив (%d элементов) ==========\n", m);
    for (i = 0; i < m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nВведите размер для уменьшения: ");
    scanf("%d", &n);

    if (n > 0 && n < m) {
        tmp = (int*)realloc(arr, n * sizeof(int));
        if (tmp != NULL) {
            arr = tmp;
            printf("========== Массив уменьшен до %d элементов ==========\n", n);
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }

    free(arr);
    arr = NULL;

    return 0;
}
