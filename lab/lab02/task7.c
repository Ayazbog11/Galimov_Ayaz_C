#include <stdio.h>

enum Course { FIRST = 1, SECOND, THIRD, FOURTH, FIFTH };

struct Student {
    char name[50];
    int age;
    enum Course course;
    float gpa;
};

struct Student students[100];
int studentCount = 0;

void myStrcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int myStrcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

const char* getCourseName(enum Course c) {
    switch(c) {
        case FIRST:  return "1 курс";
        case SECOND: return "2 курс";
        case THIRD:  return "3 курс";
        case FOURTH: return "4 курс";
        case FIFTH:  return "5 курс";
        default:     return "Неизвестно";
    }
}

void addStudent() {
    if (studentCount >= 100) {
        printf("Ошибка: достигнут максимум студентов!\n");
        return;
    }
    
    struct Student *s = &students[studentCount];
    
    printf("\n--- Добавление студента ---\n");
    printf("Имя: ");
    scanf("%s", s->name);
    printf("Возраст: ");
    scanf("%d", &s->age);
    printf("Курс (1-5): ");
    int courseNum;
    scanf("%d", &courseNum);
    s->course = (enum Course)courseNum;
    printf("Средний балл: ");
    scanf("%f", &s->gpa);
    
    studentCount++;
    printf("Студент добавлен!\n");
}

void printStudents() {
    if (studentCount == 0) {
        printf("\nСписок пуст.\n");
        return;
    }
    
    printf("\n================== Список студентов =======================\n");
    printf("№    Имя                 Возраст    Курс       Сред.балл\n");
    printf("-----------------------------------------------------------\n");
    
    int i;
    for (i = 0; i < studentCount; i++) {
        struct Student *s = &students[i];
        printf("%-4d %-20s %-10d %-10s %-10.2f\n", 
        i + 1, s->name, s->age, getCourseName(s->course), s->gpa);
    }
}

void searchByName() {
    char searchName[50];
    printf("\nВведите имя для поиска: ");
    scanf("%s", searchName);
    
    int found = 0;
    printf("\nРезультаты поиска:\n");
    
    int i;
    for (i = 0; i < studentCount; i++) {
        if (myStrcmp(students[i].name, searchName) == 0) {
            struct Student *s = &students[i];
            printf("Найден: %s, %d лет, %s, %.2f\n", 
            s->name, s->age, getCourseName(s->course), s->gpa);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Студент с именем '%s' не найден.\n", searchName);
    }
}

void sortByGPA() {
    if (studentCount < 2) {
        printf("\nНедостаточно студентов для сортировки.\n");
        return;
    }
    
    int i, j;
    for (i = 0; i < studentCount - 1; i++) {
        for (j = 0; j < studentCount - i - 1; j++) {
            if (students[j].gpa < students[j + 1].gpa) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    printf("\nСписок отсортирован по среднему баллу (убывание).\n");
}

void demonstratePointers() {
    printf("\n====== Демонстрация указателей ========+=\n");
    
    struct Student s;
    myStrcpy(s.name, "Тест");
    s.age = 20;
    s.course = SECOND;
    s.gpa = 4.0;
    
    struct Student *ptr = &s;
    
    printf("Через переменную: %s, %.2f\n", s.name, s.gpa);
    printf("Через указатель (->): %s, %.2f\n", ptr->name, ptr->gpa);
    printf("Через указатель (*ptr).: %s, %.2f\n", (*ptr).name, (*ptr).gpa);
    
    ptr->gpa = 4.5;
    printf("После изменения через указатель: %.2f\n", s.gpa);
}

void showMenu() {
    printf("\n");
    printf("=====================================\n");
    printf("     СИСТЕМА УЧЕТА СТУДЕНТОВ       \n");
    printf("=====================================\n");
    printf(" 1. Добавить студента              \n");
    printf(" 2. Вывести список студентов       \n");
    printf(" 3. Поиск по имени                 \n");
    printf(" 4. Сортировка по среднему баллу   \n");
    printf(" 5. Демонстрация указателей        \n");
    printf(" 0. Выход                          \n");
    printf("=====================================\n");
    printf("Выбор: ");
}

int main() {
    int choice;
    
    printf("=== Задание 7: Комплексное задание ===\n");
    
    // Тестовые данные
    myStrcpy(students[0].name, "Иван");
    students[0].age = 19;
    students[0].course = FIRST;
    students[0].gpa = 4.2;
    
    myStrcpy(students[1].name, "Мария");
    students[1].age = 20;
    students[1].course = SECOND;
    students[1].gpa = 4.8;
    
    myStrcpy(students[2].name, "Петр");
    students[2].age = 21;
    students[2].course = THIRD;
    students[2].gpa = 3.9;
    
    studentCount = 3;
    
    printf("Загружено %d тестовых студентов.\n", studentCount);
    
    do {
        showMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: printStudents(); break;
            case 3: searchByName(); break;
            case 4: sortByGPA(); break;
            case 5: demonstratePointers(); break;
            case 0: printf("\nДо свидания!\n"); break;
            default: printf("\nНеверный выбор!\n");
        }
    } while (choice != 0);
    
    return 0;
}