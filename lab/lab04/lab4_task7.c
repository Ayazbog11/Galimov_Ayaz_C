#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    FILE *fp;
    struct Person p1, p2;

    printf("=== Задание 7: Структуры в бинарных файлах ===\n");

    // 1. Ввод структуры
    printf("Введите имя: ");
    fgets(p1.name, 50, stdin);

    printf("Введите возраст: ");
    scanf("%d", &p1.age);

    // 2. Запись в файл
    fp = fopen("person.bin", "wb");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fwrite(&p1, sizeof(struct Person), 1, fp);
    fclose(fp);

    printf("Структура записана в файл\n");

    // 3. Чтение из файла
    fp = fopen("person.bin", "rb");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fread(&p2, sizeof(struct Person), 1, fp);
    fclose(fp);

    // 4. Вывод
    printf("\nСчитанные данные:\n");
    printf("Имя: %s", p2.name);
    printf("Возраст: %d\n", p2.age);

    return 0;
}