#include <stdio.h>
#include "apply.c"
#include "parse_number.c"
#include "parse_operator.c"
#include "evaluate.c"

int main() {
    char str[100];
    printf("Введите выражение: ");
    
    if (scanf("%[^\n]", str) != 1) {
        return 1;
    }

    int result = evaluate(str);
    printf("Результат: %d\n", result);

    return 0;
}
