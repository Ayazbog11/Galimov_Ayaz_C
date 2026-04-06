#include <Stdio.h>
#include "vivodmas.c"
#include "fill.c"
int main() {
    int n;
    printf("Введите размер массива: ");
    if (scanf("%d", &n) != 1) return 1; 
    int my_array[n]; 
    fill_mas(my_array, n);
    print_array(my_array, n);

    return 0;
}