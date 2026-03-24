#include <stdio.h>

int main() {
    int a = 100;
    int b = 200;
    int *p1 = &a; 
    int *p2 = &b; 
    printf("p1 указывает на значение: %d\n", *p1);
    printf("p2 указывает на значение: %d\n\n", *p2);
    p1 = p2; 
    printf("p1 теперь указывает на: %d\n", *p1);
    printf("p2 по-прежнему указывает на: %d\n", *p2);
    return 0;
}
