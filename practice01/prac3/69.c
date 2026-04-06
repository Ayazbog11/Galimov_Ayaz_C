#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int sum = 0, temp = i;
        while (temp > 0) {
            int d = temp % 10, fact = 1;
            for (int j = 1; j <= d; j++) fact *= j;
            sum += fact;
            temp /= 10;
        }
        if (sum == i) printf("%d ", i);
    }
    return 0;
}
