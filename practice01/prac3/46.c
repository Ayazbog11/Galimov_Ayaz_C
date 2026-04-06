#include <stdio.h>

int main() {
    int n;
    long long total_sum = 0;
    printf("Введите N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int temp = i, has_five = 0;
        while (temp > 0) {
            if (temp % 10 == 5) { has_five = 1; break; }
            temp /= 10;
        }
        if (!has_five) total_sum += i;
    }

    printf("Сумма: %lld\n", total_sum);
    return 0;
}
