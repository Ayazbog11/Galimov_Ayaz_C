#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int mas[a];
    int mas2[a]; 
    int *ptr = mas; 
    for (int i = 0; i < a; i++) {
        scanf("%d", (ptr + i));
    }
    int *ptr_src = mas;   
    int *ptr_dest = mas2; 

    for (int i = 0; i < a; i++) {
        *ptr_dest = *ptr_src; 
        ptr_src++;            
        ptr_dest++;
    }
    ptr = mas2;
    for (int i = 0; i < a; i++) {
        printf("%d ", *(ptr + i));
    }

    return 0;
}
