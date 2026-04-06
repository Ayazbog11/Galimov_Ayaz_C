#include <stdio.h>
#include "fill.c"

int main() {
    int n;
    printf("Введите размер массива: ");
    if (scanf("%d", &n) != 1) return 1;
    int my_mass[n]; 
    fill_mas(my_mass, n);
    printf("Ваш массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_mass[i]);
    }
    printf("\n");

    return 0;
}
