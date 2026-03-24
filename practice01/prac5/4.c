#include <stdio.h>

int main() {
    int need = 555;
    int *ptr = &need;
    printf("Адрес переменной  %p\n", (void*)&need);
    return 0;
}
