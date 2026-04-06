#include <stdio.h>

int main() {
    int arr[] = {12, 45, 7, 91, 23, 54};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *start = arr; 
    int *end = arr + n - 1; 
    int max = *start; 
    printf("Массив: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    while (start <= end) {
        if (*start > max) {
            max = *start;
        }
        if (*end > max) {
            max = *end;
        }
        start++;
        end--;
    }

    printf("Максимальный элемент: %d\n", max);

    return 0;
}
