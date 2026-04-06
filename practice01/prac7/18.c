#include <stdio.h>
int find_intersection(int *a, int n1, int *b, int n2, int *result) {
    int count = 0;
    
    for (int i = 0; i < n1; i++) {
        int *ptr_b = b; 
        for (int j = 0; j < n2; j++) {
            if (*(a + i) == *ptr_b) {
                *(result + count) = *ptr_b; 
                count++;
                break; 
            }
            ptr_b++;
        }
    }
    return count;
}

int main() {
    int n1 = 5, n2 = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 5, 7, 9, 1};
    int res[5]; 

    int common_count = find_intersection(arr1, n1, arr2, n2, res);

    printf("Пересечение массивов: ");
    for (int i = 0; i < common_count; i++) {
        printf("%d ", *(res + i));
    }
    printf("\nВсего найдено: %d\n", common_count);

    return 0;
}
