#include <stdio.h>

int main() {
    float a, b, c;
    printf("Введите числа a, b и c: ");
    scanf("%f %f %f", &a, &b, &c);

    float result = ((a + b) * c) / 2.0;

    printf("Результат: %.2f\n", result);

    return 0;
}
