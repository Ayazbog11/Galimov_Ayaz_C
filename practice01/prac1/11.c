#include <stdio.h>

int main() {
    int n;
    printf("Введите целое число: ");
    scanf("%d", &n);
    if (n & 1){
        printf("necheat" );
    }
    else 
    {
        printf("cheat");
    }

    return 0;
}