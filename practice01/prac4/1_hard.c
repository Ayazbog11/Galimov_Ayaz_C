#include <stdio.h>

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    long long max_so_far = arr[0];  
    long long current_max = arr[0]; 
    int start = 0, end = 0; 
    int temp_start = 0;     
    for (int i = 1; i < n; i++) {
        if (arr[i] > current_max + arr[i]) {
            current_max = arr[i];
            temp_start = i;
        } else {
            current_max += arr[i];
        }
        if (current_max > max_so_far) {
            max_so_far = current_max;
            start = temp_start;
            end = i;
        }
    }

    printf("\nМаксимальная сумма: %lld\n", max_so_far);
    printf("Границы подотрезка: от индекса %d до %d\n", start, end);
    
    printf("Сам подотрезок: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}