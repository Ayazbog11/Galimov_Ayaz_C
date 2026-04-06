#include <stdio.h>

int main(void) {
    int num;
    printf("Введите число: ");
    scanf("%d", &num);

    if (num % 2 == 0) printf("Делится на 2\n");
    else printf("Не делится на 2\n");

    if (num % 3 == 0) printf("Делится на 3\n");
    else printf("Не делится на 3\n");

    if (num % 5 == 0) printf("Делится на 5\n");
    else printf("Не делится на 5\n");

    return 0;
}