#include <stdio.h>

int main() {
    int x = 777;
    int *ptr = &x;       
    int **need = &ptr; 
    printf("Значение переменной x: %d\n", x);
    printf("Значение через ptr:    %d\n", *ptr);
    printf("Значение через): %d\n", **need);
    printf("\nАдрес x: %p\n", (void*)&x);
    printf("Адрес в ptr: %p\n", (void*)ptr);
    printf("Адрес в: %p\n", (void*)need);
    return 0;
}
