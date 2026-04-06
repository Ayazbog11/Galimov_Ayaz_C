#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    int mas[a];
    int *ptr = mas;
    for (int i = 0; i < a; i++) {
        scanf("%d", &mas[i]);
    }
    for (int i = 0; i < a; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    return 0;
}