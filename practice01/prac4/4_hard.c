#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    long long count = 0; 
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                count++;
            }
        }
    }
    printf("%lld\n", count);

    return 0;
}
