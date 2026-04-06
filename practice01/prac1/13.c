#include <stdio.h>

int main(void)
{
    int score;
    scanf("%d", &score);    
    if (score < 0 || score > 100) {
        printf("Ошибка: число должно быть в диапазоне от 0 до 100.\n");
    } 
    else if (score >= 90) {
        printf("Оценка: Отлично\n");
    } 
    else if (score >= 75) {
        printf("Оценка: Хорошо\n");
    } 
    else if (score >= 60) {
        printf("Оценка: Удовлетворительно\n");
    } 
    else {
        printf("Оценка: Неудовлетворительно\n");
    }

    return 0;
}