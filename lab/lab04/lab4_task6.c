/* Задание 6: Бинарные файлы (простые данные) */
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int arr[5] = {10, 20, 30, 40, 50};
    int read_arr[5];
    int i;

    printf("||||||||||| Задание 6: Бинарные файлы |||||||||||\n");

    // Запись в бинарный файл
    fp = fopen("binary.bin", "wb");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fwrite(arr, sizeof(int), 5, fp);
    fclose(fp);

    printf("||| Массив записан в бинарный файл |||\n");

    // Чтение из бинарного файла
    fp = fopen("binary.bin", "rb");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fread(read_arr, sizeof(int), 5, fp);
    fclose(fp);

    printf("||| Считанные данные: |||\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", read_arr[i]);
    }
    printf("\n");

    return 0;
}
