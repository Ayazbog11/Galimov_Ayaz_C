#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student student;

    char tempName[] = "Иван Иванов";
    int i = 0;

    while (tempName[i] != '\0') {
        student.name[i] = tempName[i];
        i++;
    }
    student.name[i] = '\0';

    student.age = 20;
    student.gpa = 4.5;

    printf("=========== Задание 1: Базовая структура ===========\n");
    printf("Инициализация в коде:\n");
    printf("Имя: %s\n", student.name);
    printf("Возраст: %d\n", student.age);
    printf("Средний балл: %.2f\n\n", student.gpa);

    printf("Введите данные студента:\n");

    printf("Имя: ");
    scanf("%49s", student.name);  

    printf("Возраст: ");
    scanf("%d", &student.age);

    printf("Средний балл: ");
    scanf("%f", &student.gpa);

    printf("\nВведенные данные:\n");
    printf("Имя: %s\n", student.name);
    printf("Возраст: %d\n", student.age);
    printf("Средний балл: %.2f\n", student.gpa);

    return 0;
}