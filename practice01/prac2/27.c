#include <stdio.h>

int main() {
    int n;
    printf("Введите N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 17 == 0) {
            printf("Первое число, кратное 17: %d\n", i);
            break;
        }
    }
    return 0;
}
