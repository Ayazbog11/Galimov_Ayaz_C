#include <stdio.h>

int main(void)
{
    int x = 10;
    printf("x = %d, address = %p\n", x, (void*)&x);
    return 0;
}