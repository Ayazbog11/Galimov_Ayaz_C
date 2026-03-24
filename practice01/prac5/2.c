#include <stdio.h>
int main() {
    int a, *reg;
    scanf("%d", &a);
    reg = &a;
    *reg = 25;
    printf("%d %d\n", *reg,a);
    return 0;
}