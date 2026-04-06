#include <stdio.h>

int main() {
    int n, val, max_val = -1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Введите число: ");
        scanf("%d", &val);
        if (val % 5 == 0 && (max_val == -1 || val > max_val)) {
            max_val = val;
        }
    }

    if (max_val != -1) printf("Максимальное кратное 5: %d\n", max_val);
    else printf("Чисел, кратных 5, не найдено.\n");
    return 0;
}
