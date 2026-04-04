/* Задание 7: Динамический массив структур */
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
};

void myStrcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    int n;
    struct Student *students;
    int i;
    int maxIndex;

    printf("========== Задание 7: Динамический массив структур ==========\n");

    printf("Введите количество студентов: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ошибка: количество должно быть положительным\n");
        return 1;
    }

    students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    printf("\n========== Введите данные студентов ==========\n");
    for (i = 0; i < n; i++) {
        printf("\nСтудент %d:\n", i + 1);
        printf("Имя: ");
        scanf("%s", students[i].name);
        printf("Возраст: ");
        scanf("%d", &students[i].age);
    }

    printf("\n========== Список студентов ==========\n");
    printf("%-5s %-20s %-10s\n", "№", "Имя", "Возраст");
    printf("========== ========== ==========\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-20s %-10d\n", i + 1, students[i].name, students[i].age);
    }

    maxIndex = 0;
    for (i = 1; i < n; i++) {
        if (students[i].age > students[maxIndex].age) {
            maxIndex = i;
        }
    }

    printf("\n========== Самый старший студент ==========\n");
    printf("Имя: %s\n", students[maxIndex].name);
    printf("Возраст: %d\n", students[maxIndex].age);

    free(students);
    students = NULL;

    return 0;
}
