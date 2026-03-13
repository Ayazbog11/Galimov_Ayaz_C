#include <stdio.h>
int main() {
    int x;
    scanf("%d", &x);
    printf("Formula 1: %d\n", x*x + 2*x + 1);
    printf("Formula 2: %d\n", (x+1)*(x+1) - (x-1)*(x-1));
    return 0;
}
