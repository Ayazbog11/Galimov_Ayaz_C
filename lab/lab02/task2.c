#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student students[5];
    printf("=========== Задание 2: Массив структур ===========\n");
    for (int i = 0; i < 5; i++) {
            printf("Введите данные студента %d:\n", i + 1);
    
            printf("Имя: ");
            scanf("%49s", students[i].name);  
    
            printf("Возраст: ");
            scanf("%d", &students[i].age);
    
            printf("Средний балл: ");
            scanf("%f", &students[i].gpa);
        }
    printf("\nСписок всех студентов:\n");
    printf("%-15s %-10s %-10s\n", "Имя", "Возраст", "Средний балл");
    printf("------------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-15s %-10d %-10.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
    int maxIndex = 0;
    for (int j = 1; j < 5; j++) {
        if (students[j].gpa > students[maxIndex].gpa) {
            maxIndex = j;
        }
    }
    printf("\nСтудент с самым высоким средним баллом:\n");
    printf("%s (%.2f)\n", students[maxIndex].name, students[maxIndex].gpa);
    return 0;
}