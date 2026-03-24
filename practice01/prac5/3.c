#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int *p1 = &a;
    int *p2 = &b;
    printf("До обмена: a = %d, b = %d\n", a, b);
    int temp = *p1; 
    *p1 = *p2;      
    *p2 = temp;     
    printf("После обмена: a = %d, b = %d\n", a, b);
    return 0;
}
