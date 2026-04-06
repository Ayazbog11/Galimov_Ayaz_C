#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int count = 0;
    int last_sign = 0; 
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) continue; 
        int current_sign = (nums[i] > 0) ? 1 : -1;
        if (last_sign == 0 || current_sign != last_sign) {
            count++;
            last_sign = current_sign;
        }
    }
    printf("%d\n", count);
    return 0;
}
