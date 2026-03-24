#include <stdio.h>

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int arr[n], dp[n];
    printf("Введите элементы массива: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = 1; 
    }

    int max_total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max_total) {
            max_total = dp[i];
        }
    }

    printf("Длина наибольшей возрастающей подпоследовательности: %d\n", max_total);

    return 0;
}
