/* Задание 5: Удаление элемента */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int *tmp;
    int index;
    int i;

    printf("========== Задание 5: Удаление элемента ==========\n");

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

    printf("\nВведите индекс элемента для удаления (0-%d): ", n - 1);
    scanf("%d", &index);

    if (index < 0 || index >= n) {
        printf("Ошибка: неверный индекс\n");
        free(arr);
        return 1;
    }

    for (i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    tmp = (int*)realloc(arr, n * sizeof(int));
    if (tmp != NULL || n == 0) {
        arr = tmp;
    }

    printf("\n========== Массив после удаления ==========\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (n > 0) {
        free(arr);
    }
    arr = NULL;

    return 0;
}
