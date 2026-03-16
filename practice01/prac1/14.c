#include <stdio.h>

int main(void) {
    int score;
    printf("Введите число от 1 до 7: ");
    scanf("%d", &score);

    switch (score) {
        case 1: printf("Понедельник\n"); break;
        case 2: printf("Вторник\n");     break;
        case 3: printf("Среда\n");       break;
        case 4: printf("Четверг\n");     break;
        case 5: printf("Пятница\n");     break;
        case 6: printf("Суббота\n");     break;
        case 7: printf("Воскресенье\n"); break;
        default: 
            printf("Ошибка: введите число именно от 1 до 7.\n");
            break;
    }

    return 0;
}