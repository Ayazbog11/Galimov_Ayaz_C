#include <stdio.h>

int main() {
    int num1, num2;
    printf("Введите два числа: ");
    scanf("%d %d", &num1, &num2);
    printf("Остаток: %d\n", num1 % num2);
    return 0;
}
