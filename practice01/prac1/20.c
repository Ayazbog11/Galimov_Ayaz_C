#include <stdio.h>

int main() {
    float a, b, c;

    printf("Введите три числа через пробел: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a + b == c) {
        printf("Магия! %.2f + %.2f равно %.2f\n", a, b, c);
    } else {
        printf("Увы, это обычные числа. Сумма первых двух: %.2f\n", a + b);
    }

    return 0;
}
