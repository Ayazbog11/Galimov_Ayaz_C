/* Задание 8: Массив структур */
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    FILE *fp;
    struct Person people[3];
    struct Person read_people[3];
    int i;

    printf("# Задание 8: Массив структур #\n");

    // Ввод данных
    printf("Введите данные 3 человек:\n");
    for (i = 0; i < 3; i++) {
        printf("\nЧеловек %d:\n", i + 1);
        printf("Имя: ");
        scanf("%s", people[i].name);
        printf("Возраст: ");
        scanf("%d", &people[i].age);
    }

    // Запись в файл
    fp = fopen("people.bin", "wb");
    if (fp == NULL) {
        printf("# Ошибка открытия файла #\n");
        return 1;
    }

    fwrite(people, sizeof(struct Person), 3, fp);
    fclose(fp);

    printf("\n# Массив записан #\n");

    // Чтение из файла
    fp = fopen("people.bin", "rb");
    if (fp == NULL) {
        printf("# Ошибка открытия файла #\n");
        return 1;
    }

    fread(read_people, sizeof(struct Person), 3, fp);
    fclose(fp);

    printf("# Считанные данные #\n");
    for (i = 0; i < 3; i++) {
        printf("%d. %s - %d лет\n", i + 1, read_people[i].name, read_people[i].age);
    }

    return 0;
}
