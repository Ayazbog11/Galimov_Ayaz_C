// это надо чтоб компилятор знал что это за типы и функции, которые мы используем в других файлах
#ifndef PERSON_H // Include guard - защита от двойного включения
#define PERSON_H // Если файл подключили дважды, второй раз игнорируется


// Здесь ТОЛЬКО объявления (декларации), но не реализации функций и глобальных переменных
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <float.h>

//глобальные переменные
typedef struct {
    char name[50];
    int age;
    float height;
    int birth_year;
} Person;

// Внешние переменные для доступа из других файлов
extern Person *people;
extern int count;
extern int capacity;

// Функции для работы с данными обявления
void add_person(void);
void print_all(void);
void sort_by_name(void);
void sort_by_age(void);
void show_statistics(void);
void search_by_name(void);
void search_by_age_range(void);
void save_to_file(void);
void load_from_file(void);
void exit_program(void);


int validate_name(const char *name);
int validate_positive_int(int value);
int validate_positive_float(float value);


void save_binary(const char *filename);
void load_binary(const char *filename);


int compare_by_name(const void *a, const void *b);
int compare_by_age(const void *a, const void *b);


float calculate_average_age(void);
float find_max_height(void);
int calculate_real_age(int birth_year);


void clear_input_buffer(void);
void print_separator(void);
void pause_screen(void);

// мой любимый полиморфизм Макрос для форматированного вывода числовых значений в статистике, чтобы они были выровнены по правому краю
//  как работает 
// Макрос print_value(x) — псевдополиморфная функция для печати различных типов
// Использует C11 _Generic для выбора подходящего printf в зависимости от типа переменной:
// - int   → выводится через %d ... 
// - default → если тип не указан, выводится "Unknown type"
// Позволяет писать один код для разных типов, вместо нескольких printf или if-ов
#define print_value(x) _Generic((x), \
    int: printf("%d", x), \
    float: printf("%.2f", x), \
    double: printf("%.2f", x), \
    char*: printf("%s", x), \
    default: printf("Unknown type") \
)

#endif