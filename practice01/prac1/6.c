#include <stdio.h>

int main(void)
{
    int x,y,z;
    scanf("%d %d %d", &x, &y, &z);
    printf("%f\n", (float)(x+y+z)/3.0);
}