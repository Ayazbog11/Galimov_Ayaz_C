#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int max = a[0];
    int sec = -2147483648;

    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            sec = max;    
            max = a[i];   
        } else if (a[i] > sec && a[i] < max) {
            sec = a[i];   
        }
    }
    printf("%d\n", sec);

    return 0;
}
