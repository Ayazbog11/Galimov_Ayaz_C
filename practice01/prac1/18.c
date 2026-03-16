#include <stdio.h>
#include <math.h>
int main(void) {
    int num;
    int int_max = pow(2, 31) - 1; 

    printf("Введите число типа int: ");
    scanf("%d", &num);

    int result = num + int_max;

    printf("INT_MAX: %d\n", int_max);
    printf("Результат сложения: %d\n", result);

    return 0;
}
