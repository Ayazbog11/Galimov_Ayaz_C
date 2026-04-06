#include "person.h"
// Реализация функций для работы с данными о людях
void add_person(void) {
    // Проверяем, нужно ли расширить массив для хранения новых данных
    if (count >= capacity) { // Если текущий счетчик достиг емкости, нужно расширить массив
        capacity = (capacity == 0) ? 2 : capacity * 2; // Увеличиваем емкость (двойной размер или начинаем с 2)
        people = realloc(people, capacity * sizeof(Person)); // Перераспределение памяти для массива структур Person
        if (!people) { // Проверка успешного выделения памяти
            printf("Memory allocation failed!\n"); // Сообщаем об ошибке выделения памяти
            exit(1);
        }
    }
    // Временная переменная для хранения данных нового человека, который будет добавлен в массив
    Person p;
    char name_buffer[100];
    // Сбор данных о человеке с помощью ввода пользователя, с валидацией каждого поля
    printf("Enter name: ");
    fgets(name_buffer, sizeof(name_buffer), stdin);
    name_buffer[strcspn(name_buffer, "\n")] = 0;
    // Валидация имени: не должно быть пустым и должно содержать только буквы и пробелы
    if (!validate_name(name_buffer)) {
        printf("Error: Name must contain only letters and spaces!\n");
        return;
    }
    // Копируем валидированное имя в структуру Person для хранения
    strcpy(p.name, name_buffer);
    // Ввод и валидация возраста: должно быть положительным целым числом
    printf("Enter age: ");
    int age;
    if (scanf("%d", &age) != 1 || !validate_positive_int(age)) { // Проверка успешности чтения и валидности возраста
        printf("Error: Age must be a positive number!\n");
        clear_input_buffer();
        return;
    }
    // Сохранение валидированного возраста в структуре Person
    p.age = age;
    // Ввод и валидация роста: должно быть положительным числом с плавающей точкой
    printf("Enter height (in meters): ");
    float height;
    if (scanf("%f", &height) != 1 || !validate_positive_float(height)) { // Проверка успешности чтения и валидности роста
        printf("Error: Height must be a positive number!\n");
        clear_input_buffer(); // Очистка буфера ввода при ошибке, чтобы избежать проблем с последующим вводом
        return;
    }
    // Сохранение валидированного роста в структуре Person
    p.height = height;
    // Ввод и валидация года рождения: должно быть положительным целым числом
    printf("Enter birth year: ");
    if (scanf("%d", &p.birth_year) != 1 || !validate_positive_int(p.birth_year)) { // Проверка успешности чтения и валидности года рождения
        printf("Error: Birth year must be positive!\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();
    
    // Вычисление реального возраста на основе текущей даты и года рождения, и вывод этой информации пользователю
    int real_age = calculate_real_age(p.birth_year);
    printf("Real age (calculated from current date): %d years\n", real_age); // Это может помочь пользователю понять, если он ошибся при вводе года рождения
    
    people[count++] = p; // Добавляем новую структуру Person в массив и увеличиваем счетчик
    printf("Person added successfully! Total records: %d\n", count);
}

void print_all(void) { // Вывод всех записей о людях в табличном формате
    if (count == 0) { // Проверка, есть ли записи для вывода
        printf("No records found.\n");
        return;
    }
    // Вывод заголовков таблицы с выравниванием и разделителями для лучшей читаемости
    print_separator(); // Вывод разделителя для визуального отделения заголовков от данных
    printf("%-20s | %-5s | %-8s | %-10s\n", "Name", "Age", "Height", "Birth Year"); // Заголовки столбцов с выравниванием по левому краю для имени и по центру для остальных полей
    print_separator();
    
    // Вывод каждой записи о человеке с форматированием для выравнивания данных в столбцах
    for (int i = 0; i < count; i++) { 
        printf("%-20s | %-5d | %-8.2f | %-10d\n", 
        people[i].name, people[i].age, people[i].height, people[i].birth_year);
    }
    print_separator();
}
// Функция для выхода из программы, которая освобождает выделенную память и выводит прощальное сообщение
void exit_program(void) {
    if (people) {
        free(people);
        people = NULL;
    }
    printf("Saving data if needed... Goodbye!\n");
}