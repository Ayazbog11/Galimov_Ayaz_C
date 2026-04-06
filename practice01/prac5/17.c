#include <stdio.h>

int main() {
    int n;
    printf("Размер массива: ");
    scanf("%d", &n);

    int mas[n];
    int *ptr = mas;

    printf("Элементы: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", (ptr + i));
    }
    int *find = mas; 
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (*find < 0) {
            printf("Первый отрицательный: %d (индекс %d)\n", *find, i);
            found = 1;
            break; 
        }
        find++; 
    }

    if (!found) {
        printf("Отрицательных элементов нет.\n");
    }

    return 0;
}
