#include <stdio.h>

int main() {
    int n;
    long long S;
    scanf("%d %lld", &n, &S);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    long long count = 0;
    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += nums[j];
            if (current_sum == S) {
                count++;
            }
        }
    }
    printf("%lld\n", count);
    return 0;
}
