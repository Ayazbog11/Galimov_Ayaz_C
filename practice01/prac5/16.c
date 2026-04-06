#include <stdio.h>

int main() {
    int a;
    printf("Введите размер массивов: ");
    scanf("%d", &a); 

    int mas[a];
    int mas2[a]; 
    int count = 0; 

    int *ptr1 = mas;
    printf("Элементы 1-го массива: ");
    for (int i = 0; i < a; i++) {
        scanf("%d", (ptr1 + i));
    }

    int *ptr2 = mas2;
    printf("Элементы 2-го массива: ");
    for (int i = 0; i < a; i++) {
        scanf("%d", (ptr2 + i));
    }

    int *ptr_src = mas;   
    int *ptr_dest = mas2; 

    for (int i = 0; i < a; i++) {
        if (*ptr_src > *ptr_dest) { 
            count++;
        } else if (*ptr_src < *ptr_dest) {
            count--;
        }
        
        ptr_src++; 
        ptr_dest++;
    }

    if (count > 0) {
        printf("The first array is greater.\n");
    } else if (count < 0) {
        printf("The second array is greater.\n");
    } else {
        printf("The arrays are equal or have same balance.\n");
    }

    return 0;
}
