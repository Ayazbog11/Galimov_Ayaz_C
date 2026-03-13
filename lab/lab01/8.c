#include <stdio.h>
int main() {
    int x = 2147483647; // Максимум для signed int
    printf("Результат: %d\n", x + 1);  // Произойдет переход в отрицательный диапазон
    return 0;
}
