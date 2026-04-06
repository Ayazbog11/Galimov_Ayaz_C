#include <stdio.h>
long long sum(int n, int c) {
    return n + c;
}
void main(){
    int a = 1, b = 2;
    printf("Сумма %d и %d равна %d\n", a, b, sum(a, b));
}