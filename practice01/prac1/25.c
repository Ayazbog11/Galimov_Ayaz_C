#include <stdio.h>

int main() {
    double n1, n2;
    char op;

    printf("Введите первое число, операцию (+, -, *, /) и второе число: ");
    scanf("%lf %c %lf", &n1, &op, &n2);

    switch (op) {
        case '+': printf("%.2f + %.2f = %.2f\n", n1, n2, n1 + n2); break;
        case '-': printf("%.2f - %.2f = %.2f\n", n1, n2, n1 - n2); break;
        case '*': printf("%.2f * %.2f = %.2f\n", n1, n2, n1 * n2); break;
        case '/': 
            if (n2 != 0) printf("%.2f / %.2f = %.2f\n", n1, n2, n1 / n2);
            else printf("Ошибка: деление на ноль!\n");
            break;
        default: printf("Ошибка: неизвестная операция.\n");
    }

    return 0;
}
