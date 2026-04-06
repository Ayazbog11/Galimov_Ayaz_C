#include <stdio.h>

int main() {
    int n, num, count = 0;
    
    printf("Введите количество чисел N: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(num % 7 == 0) {
            count++;
        }
    }
    
    printf("Делятся на 7: %d\n", count);
    return 0;
}
