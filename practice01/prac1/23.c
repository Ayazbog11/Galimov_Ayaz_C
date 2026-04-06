#include <stdio.h>

int main() {
    int a, b;
    printf("Введите числа a и b: ");
    scanf("%d %d", &a, &b);

    if (a > b) {
        printf("a больше b (%d > %d)\n", a, b);
    } else if (a < b) {
        printf("a меньше b (%d < %d)\n", a, b);
    } else {
        printf("Числа равны (%d = %d)\n", a, b);
    }

    return 0;
}
