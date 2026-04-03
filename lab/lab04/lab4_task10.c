/* Задание 10: Размер файла */
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    long size;

    printf("[===] Задание 10: Размер файла [===]\n");

    // Создание тестового файла
    fp = fopen("size_test.txt", "w");
    if (fp == NULL) {
        printf("Ошибка создания файла\n");
        return 1;
    }

    fprintf(fp, "Hello, World!\n");
    fprintf(fp, "This is a test file.\n");
    fclose(fp);

    // Определение размера
    fp = fopen("size_test.txt", "r");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fclose(fp);

    printf("[===] Размер файла: %ld байт [===]\n", size);

    return 0;
}
