#include <stdio.h>
enum Day {
    MONDAY,     
    TUESDAY,    
    WEDNESDAY,  
    THURSDAY,   
    FRIDAY,     
    SATURDAY,   
    SUNDAY      
};

struct Schedule {
    char task[100];
    enum Day day;
    int hour;
};

void printDay(enum Day day) {
    switch(day) {
        case MONDAY:    printf("Понедельник"); break;
        case TUESDAY:   printf("Вторник"); break;
        case WEDNESDAY: printf("Среда"); break;
        case THURSDAY:  printf("Четверг"); break;
        case FRIDAY:    printf("Пятница"); break;
        case SATURDAY:  printf("Суббота"); break;
        case SUNDAY:    printf("Воскресенье"); break;
        default:        printf("Неизвестный день");
    }
}

const char* getDayName(enum Day day) {
    switch(day) {
        case MONDAY:    return "Понедельник";
        case TUESDAY:   return "Вторник";
        case WEDNESDAY: return "Среда";
        case THURSDAY:  return "Четверг";
        case FRIDAY:    return "Пятница";
        case SATURDAY:  return "Суббота";
        case SUNDAY:    return "Воскресенье";
        default:        return "Неизвестно";
    }
}

int main() {
    printf("=========== Задание 5: Перечисления (enum) ===========\n");
    enum Day today = WEDNESDAY;
    enum Day tomorrow = THURSDAY;

    printf("\nСегодня: ");
    printDay(today);
    printf(" (значение: %d)\n", today);

    printf("Завтра: ");
    printDay(tomorrow);
    printf(" (значение: %d)\n", tomorrow);
    printf("\nИспользование enum в структуре:\n");

    // struct Schedule schedules[3] = {
    //     {"Лекция по C", MONDAY, 9},
    //     {"Лабораторная работа", WEDNESDAY, 14}, некрасиво выводит
    //     {"Консультация", FRIDAY, 16}
    // };
    // printf("%-25s %-15s %-10s\n", "Задача", "День", "Время");
    // for (int i = 0; i < 3; i++) {
    //     printf("%-25s %-15s %d:00\n", schedules[i].task,getDayName(schedules[i].day),schedules[i].hour);
    // }
    struct Schedule schedules[3] = {
    {"Lecture", MONDAY, 9},
    {"Lab work", WEDNESDAY, 14},
    {"Consultation", FRIDAY, 16}  //стало чуть красивее, но не идеально из-за русского текста
    };
    printf("%-25s %-25s %-10s\n", "Task", "Day", "Time");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        printf("%-25s %-25s %d:00\n", schedules[i].task, getDayName(schedules[i].day),schedules[i].hour);
}
    printf("\nПроверка на выходной:\n");
    enum Day checkDay = SATURDAY;
    if (checkDay == SATURDAY || checkDay == SUNDAY) { 
        printf("%s - выходной!\n", getDayName(checkDay));
    } else {
        printf("%s - рабочий день.\n", getDayName(checkDay));
    }
    return 0;
}