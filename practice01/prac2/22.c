#include <stdio.h>

int main() {
    int n;
    printf("Введите N: ");
    scanf("%d", &n);

    printf("Делители: ");
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) printf("%d ", i);
    }
    return 0;
}
