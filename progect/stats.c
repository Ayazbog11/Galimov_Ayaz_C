#include "person.h"
// Реализация функций для статистики: средний возраст, максимальный рост, реальный возраст на основе года рождения
float calculate_average_age(void) {
    if (count == 0) return 0;
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += people[i].age;
    }
    return (float)sum / count;
}

// Функция для нахождения максимального роста среди всех записей
float find_max_height(void) {
    if (count == 0) return 0;
    float max = people[0].height;
    for (int i = 1; i < count; i++) {
        if (people[i].height > max) {
            max = people[i].height;
        }
    }
    return max;
}

// Функция для вычисления реального возраста на основе текущей даты и года рождения
int calculate_real_age(int birth_year) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    int current_year = tm_info->tm_year + 1900;
    return current_year - birth_year;
}

// Функция для отображения статистики: общее количество записей, средний возраст, максимальный рост, используемая память
void show_statistics(void) {
    if (count == 0) {
        printf("No data available for statistics!\n");
        return;
    }
    
    print_separator(); // Визуальное отделение статистики от других пунктов меню
    printf("STATISTICS REPORT\n");
    print_separator();
    
    printf("Total records: ");
    print_value(count); // Вывод общего количества записей в статистике
    printf("\n");
    
    printf("Average age: ");
    print_value(calculate_average_age());
    printf(" years\n");
    
    printf("Maximum height: ");
    print_value(find_max_height());
    printf(" meters\n");
    // Вывод используемой памяти на основе количества записей и размера структуры Person
    printf("Memory used: %zu bytes\n", count * sizeof(Person));
    print_separator(); // Визуальное отделение статистики от других пунктов меню
}