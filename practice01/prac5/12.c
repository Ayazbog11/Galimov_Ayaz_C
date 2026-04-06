#include <stdio.h>
int main() {
    int a, sim;
    scanf("%d", &a);
    int mas[a];
    int *ptr = mas;
    for (int i = 0; i < a; i++) {
        scanf("%d", &mas[i]);
    }
    for (int i = 0; i < a; i++) {
        sim += *ptr;
        ptr++;
    }
    printf("%d\n", sim);
    return 0;
}