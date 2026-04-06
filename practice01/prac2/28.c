#include <stdio.h>

int main() {
    int n;
    printf("Введите N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int temp = i, has_three = 0;
        while (temp > 0) {
            if (temp % 10 == 3) {
                has_three = 1;
                break;
            }
            temp /= 10;
        }
        if (has_three) continue;
        printf("%d ", i);
    }
    return 0;
}
