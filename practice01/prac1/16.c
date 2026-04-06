#include <stdio.h>

int main(void) {
    int x;
    printf("Введите x: ");
    scanf("%d", &x);

    if (x > 0) {
        printf("Результат (x^2): %d\n", x * x);
    } 
    else if (x == 0) {
        printf("Результат: 0\n");
    } 
    else { 
        printf("Результат (-x): %d\n", -x);
    }

    return 0;
}