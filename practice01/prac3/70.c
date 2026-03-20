#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        int a = i;
        int b = k;
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        if (a == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}
