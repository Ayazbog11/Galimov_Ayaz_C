#include <stdio.h>

int main() {
    int *ptr = NULL; 
    if (ptr == NULL) {
        printf("Указатель ptr равен NULL. К нему нельзя обращаться!\n");
    } else {
        printf("Значение через указатель: %d\n", *ptr);
    }
    int value = 123;
    ptr = &value;
    if (ptr != NULL) {
        printf("Теперь ptr НЕ NULL. Значение: %d\n", *ptr);
    }

    return 0;
}
