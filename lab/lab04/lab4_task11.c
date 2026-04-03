#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int ch; 

    printf("{-} Задание 11: Проверка конца файла и ошибок {-}\n");

    // Создание тестового файла
    fp = fopen("eof_test.txt", "w");
    if (fp == NULL) {
        printf("{- Ошибка создания файла -}\n");
        return 1;
    }

    fprintf(fp, "Test");
    fclose(fp);

    // Чтение до конца файла
    fp = fopen("eof_test.txt", "r");
    if (fp == NULL) {
        printf("{- Ошибка открытия файла -}\n");
        return 1;
    }

    printf("{- Чтение файла -}\n");
    while ((ch = getc(fp)) != EOF) {
        putchar(ch);
    }
    printf("\n");

    // Проверка конца файла
    if (feof(fp)) {
        printf("{- Достигнут конец файла -}\n");
    }

    // Проверка ошибок
    if (ferror(fp)) {
        printf("{- Ошибка при чтении -}\n");
    } else {
        printf("{- Ошибок нет -}\n");
    }

    fclose(fp);

    return 0;
}