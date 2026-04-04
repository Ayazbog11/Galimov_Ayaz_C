#include "person.h"

// Реализация функций для поиска людей по имени и возрастному диапазону
void search_by_name(void) {
    if (count == 0) { // Проверка, есть ли записи для поиска
        printf("No records to search!\n");
        return;
    }
    // Получаем имя для поиска от пользователя
    char name[50];
    printf("Enter name to search: ");
    fgets(name, sizeof(name), stdin); // Чтение имени с пробелами
    name[strcspn(name, "\n")] = 0; // Удаление символа новой строки, который добавляет fgets
    // Поиск по имени (без учета регистра) и вывод найденных записей
    int found = 0; // Флаг для отслеживания, найден ли кто-то с таким именем
    printf("\nSearch results:\n");
    for (int i = 0; i < count; i++) { // Перебор всех записей для поиска совпадений по имени
        if (strcasecmp(people[i].name, name) == 0) { // Сравнение имен без учета регистра
            printf("Found: %s | Age: %d | Height: %.2f | Birth year: %d\n", // Вывод информации о найденной записи
            people[i].name, people[i].age, people[i].height, people[i].birth_year);
            found = 1;
        }
    }
    // Если после проверки всех записей флаг found остался 0, значит никто не был найден, и мы сообщаем об этом пользователю
    if (!found) {
        printf("No person found with name '%s'.\n", name);
    }
}
// Функция для поиска людей в заданном возрастном диапазоне и вывода их информации
void search_by_age_range(void) { 
    if (count == 0) { // Проверка, есть ли записи для поиска
        printf("No records to search!\n");
        return;
    }
    // Получаем минимальный и максимальный возраст для поиска от пользователя
    int min_age, max_age;
    printf("Enter minimum age: ");
    scanf("%d", &min_age);
    printf("Enter maximum age: ");
    scanf("%d", &max_age);
    clear_input_buffer(); // Очистка буфера после чтения чисел, чтобы избежать проблем с последующим вводом строк
    // Проверка валидности введенного возрастного диапазона: минимальный возраст должен быть меньше или равен максимальному, и оба должны быть неотрицательными
    if (min_age > max_age || min_age < 0) { // Если минимальный возраст больше максимального или если минимальный возраст отрицательный, выводим сообщение об ошибке и прекращаем выполнение функции
        printf("Invalid age range!\n");
        return;
    }
    // Поиск по возрастному диапазону и вывод найденных записей
    int found = 0;
    printf("\nPersons aged %d-%d:\n", min_age, max_age); // Вывод заголовка для результатов поиска по возрасту  
    for (int i = 0; i < count; i++) { // Перебор всех записей для поиска совпадений по возрасту
        if (people[i].age >= min_age && people[i].age <= max_age) { // Проверка, входит ли возраст текущей записи в заданный диапазон
            printf("%s | Age: %d | Height: %.2f | Birth year: %d\n", // Вывод информации о найденной записи
            people[i].name, people[i].age, people[i].height, people[i].birth_year);
            found = 1;
        }
    }
    // Если после проверки всех записей флаг found остался 0, значит никто не был найден в этом возрастном диапазоне, и мы сообщаем об этом пользователю
    if (!found) {
        printf("No persons found in this age range.\n");
    }
}