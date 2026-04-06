#include <stdio.h>

int main() {
    int value = 500;        
    int *ptr = &value;     
    int **pptr = &ptr;      
    printf("Значение value: %d\n", value);
    **pptr = 999;
    printf("Новое значение value: %d\n", value);
    printf("Значение через *ptr:  %d\n", *ptr);
    printf("Значение через **pptr: %d\n", **pptr);
    return 0;
}
