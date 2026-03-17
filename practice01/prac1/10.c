#include <stdio.h>

int main() {
    int n;
    printf("Введите целое число: ");
    scanf("%d", &n);
    printf("n & 1  (И)    : %d\n", n & 1);
    printf("n | 1  (ИЛИ)  : %d\n", n | 1);
    printf("n ^ 1  (XOR)  : %d\n", n ^ 1);
    printf("~n     (НЕ)   : %d\n", ~n);

    return 0;
}
