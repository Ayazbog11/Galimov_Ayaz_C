#include <stdio.h>
int main() {
    int x = 10, y = 10;
    int *p1 = &x, *p2 = &x, *p3 = &y;
    if (p1 == p2) printf("p1 и p2 указывают на один адрес\n");
    if (p1 != p3) printf("p1 и p3 указывают на разные адреса\n");
    return 0;
}
