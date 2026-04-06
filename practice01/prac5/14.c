#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    int mas[a];
    for (int i = 0; i < a; i++) {
        scanf("%d", &mas[i]);
    }
    int *left = mas;          
    int *right = mas + a - 1; 
    int temp;

    while (left < right) {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    for (int i = 0; i < a; i++) {
        printf("%d ", mas[i]);
    }

    return 0;
}
