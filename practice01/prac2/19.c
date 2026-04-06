#include <stdio.h>

int main() {
    int n;
    printf("Введите N: ");
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            printf("%d в квадрате = %d\n", i, i * i);
        }
    }
    return 0;
}
