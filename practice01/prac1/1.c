#include <stdio.h>

int main(void)
{
    int x = 10;
    printf("hello world\n");
    printf("x = %d, address = %p\n", x, (void*)&x);
    return 0;
}