/* Задание 3: Поиск элементов */
#include <stdio.h>
#include <stdlib.h>

int findMax(int *arr, int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int *arr, int n) {
    int min = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int findSum(int *arr, int n) {
    int sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    int *arr;
    int i;

    printf("========== Задание 3: Поиск элементов ==========\n");

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

    printf("\n========== Массив ==========\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\n========== Результаты ==========\n");
    printf("Максимальный элемент: %d\n", findMax(arr, n));
    printf("Минимальный элемент: %d\n", findMin(arr, n));
    printf("Сумма элементов: %d\n", findSum(arr, n));

    free(arr);
    arr = NULL;

    return 0;
}
