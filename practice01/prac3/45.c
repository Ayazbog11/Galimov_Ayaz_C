#include <stdio.h>

int main() {
    int n, only_even = 1;
    printf("Введите N: ");
    scanf("%d", &n);

    while (n > 0) {
        if ((n % 10) % 2 != 0) {
            only_even = 0;
            break;
        }
        n /= 10;
    }

    if (only_even) printf("Да, все четные\n");
    else printf("Нет, есть нечетные\n");
    return 0;
}
