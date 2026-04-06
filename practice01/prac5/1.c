#include <stdio.h>
int main() {
    int a, *reg;
    scanf("%d", &a);
    reg = &a;
    printf("%p\n", reg);
    return 0;
}