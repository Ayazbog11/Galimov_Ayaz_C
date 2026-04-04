#include "person.h"
// Реализация функций для сортировки данных по имени и возрасту
int compare_by_name(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return strcmp(p1->name, p2->name);
}

// Сравнение по возрасту для сортировки
int compare_by_age(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return p1->age - p2->age;
}

// Функция для сортировки по имени (алфавитно)
void sort_by_name(void) { // Проверка, есть ли достаточно записей для сортировки (не менее 2)
    if (count < 2) {
        printf("Not enough records to sort!\n");
        return;
    } // Сортировка массива структур Person по имени с помощью функции qsort и компаратора compare_by_name
    qsort(people, count, sizeof(Person), compare_by_name); // Сортировка массива структур Person по имени с помощью функции qsort и компаратора compare_by_name
    printf("Sorted %d records by name (alphabetically).\n", count);
}

// Функция для сортировки по возрасту (по возрастанию)
void sort_by_age(void) {
    if (count < 2) {
        printf("Not enough records to sort!\n");
        return;
    }
    // Сортировка массива структур Person по возрасту с помощью функции qsort и компаратора compare_by_age
    qsort(people, count, sizeof(Person), compare_by_age);
    printf("Sorted %d records by age.\n", count);
}