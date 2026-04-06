#include <stdio.h>

int main() {
    int num, count = 0;
    
    printf("Вводите числа (0 для выхода): ");
    scanf("%d", &num);
    
    while(num != 0) {
        count++;
        scanf("%d", &num);
    }
    
    printf("Количество введенных чисел: %d\n", count);
    return 0;
}
