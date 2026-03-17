#include <stdio.h>

int main() {
    int num, sum = 0;
    
    printf("Вводите числа (0 для выхода): ");
    while(scanf("%d", &num) && num != 0) {
        if(num > 0) {
            sum += num;
        }
    }
    
    printf("Сумма положительных: %d\n", sum);
    return 0;
}
