#include <stdio.h>

int main() {
    int a = 10;
    char c = 'A';
    double d = 5.5;
    int *pInt = &a;
    char *pChar = &c;
    double *pDouble = &d;
    printf("Размер указателя на int:    %zu байт(а)\n", sizeof(pInt));
    printf("Размер указателя на char:   %zu байт(а)\n", sizeof(pChar));
    printf("Размер указателя на double: %zu байт(а)\n", sizeof(pDouble));
    printf("Размер самой переменной char:   %zu байт\n", sizeof(c));
    printf("Размер самой переменной double: %zu байт\n", sizeof(d));

    return 0;
}
