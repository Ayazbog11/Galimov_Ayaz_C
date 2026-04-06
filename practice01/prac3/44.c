#include <stdio.h>

int main() {
    int n, rev = 0;
    printf("Введите N: ");
    scanf("%d", &n);

    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    printf("Перевернутое: %d\n", rev);
    return 0;
}
