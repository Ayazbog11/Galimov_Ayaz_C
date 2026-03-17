#include <stdio.h>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j == k) printf("(%d, %d)\n", i, j);
        }
    }
    return 0;
}
