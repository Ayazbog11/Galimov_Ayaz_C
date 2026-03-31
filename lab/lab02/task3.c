#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char name[50];
    struct Date birthDate;
};

int main() {
    struct Person people[4];
    int i;
    printf("=========== Задание 3: Вложенные структуры ===========\n");
    for (i = 0; i < 4; i++) {
        printf("Введите данные человека %d:\n", i + 1);
        
        printf("Имя: ");
        scanf("%49s", people[i].name);  
        
        printf("Дата рождения (день месяц год): ");
        scanf("%d %d %d", &people[i].birthDate.day, &people[i].birthDate.month, &people[i].birthDate.year);
    }
    printf("\nВсе люди:\n");
    printf("%-15s %-15s\n", "Имя", "Дата рождения");
    printf("---------------------------------\n");

    for (i = 0; i < 4; i++) {
        printf("%-15s %02d/%02d/%04d\n", people[i].name, people[i].birthDate.day, people[i].birthDate.month, people[i].birthDate.year);
    }
    printf("\nЛюди, родившиеся после 2000 года:\n");
    printf("%-15s %-15s\n", "Имя", "Дата рождения");
    printf("---------------------------------\n");

    for (i = 0; i < 4; i++) {
        if (people[i].birthDate.year > 2000) {
            printf("%-15s %02d/%02d/%04d\n", people[i].name, people[i].birthDate.day, people[i].birthDate.month, people[i].birthDate.year);
        }
    }
    return 0;
}