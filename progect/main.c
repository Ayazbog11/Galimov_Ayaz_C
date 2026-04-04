#include "person.h"

// Глобальные переменные для хранения данных о людях
Person *people = NULL;
int count = 0;
int capacity = 0;

// Массив указателей на функции для меню
void (*menu_functions[])(void) = {
    add_person,
    print_all,
    sort_by_name,
    sort_by_age,
    show_statistics,
    search_by_name,
    search_by_age_range,
    save_to_file,
    load_from_file,
    exit_program
};
// Массив строк для отображения пунктов меню
const char *menu_items[] = {
    "Add person",
    "Print all",
    "Sort by name",
    "Sort by age",
    "Statistics",
    "Search by name",
    "Search by age range",
    "Save to file",
    "Load from file",
    "Exit"
};

int main() {
    int choice;
    int menu_size = sizeof(menu_functions) / sizeof(menu_functions[0]); // Количество пунктов меню
    
    printf("Personal Data Manager\n");
    print_separator();
    
    while (1) { // Бесконечный цикл для отображения меню после каждой операции
        printf("\n=== MENU ===\n");
        for (int i = 0; i < menu_size; i++) { 
            printf("%d. %s\n", i + 1, menu_items[i]);
        }
        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer(); // Очистка буфера ввода при неверном вводе
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        clear_input_buffer(); // Очистка буфера после чтения числа
        
        if (choice >= 1 && choice <= menu_size) {
            menu_functions[choice - 1](); // Вызов через указатель на функцию!
            if (choice == menu_size) break; // Если выбрали "Exit", выходим из цикла
        } else {
            printf("Invalid choice! Please select 1-%d\n", menu_size); // Проверка на допустимый диапазон
        }
    }
    
    return 0;
}