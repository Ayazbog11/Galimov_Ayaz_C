#include <stdio.h>

int main(void) {
    int a, b;
    printf("Введите два числа (a и b): ");
    scanf("%d %d", &a, &b);

    a = a + b; 
    b = a - b; 
    a = a - b; 

    printf("Результат: a = %d, b = %d\n", a, b);
    return 0;
}
