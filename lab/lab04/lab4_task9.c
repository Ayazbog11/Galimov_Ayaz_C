#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char str[] = "ABCDEFGHIJ";
    char ch;
    int pos;

    printf("=== Задание 9: Позиционирование в файле ===\n");

    // 1. Создаём файл и записываем данные
    fp = fopen("seek.txt", "w");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fputs(str, fp);
    fclose(fp);

    // 2. Открыть файл
    fp = fopen("seek.txt", "r");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    printf("Введите позицию (0-9): ");
    scanf("%d", &pos);

    // Проверка позиции
    if (pos < 0 || pos >= 10) {
        printf("Неверная позиция\n");
        fclose(fp);
        return 1;
    }

    // 3. Перемещение
    fseek(fp, pos, SEEK_SET);

    // 4. Чтение и вывод
    printf("Данные с позиции %d: ", pos);
    while ((ch = getc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    return 0;
}