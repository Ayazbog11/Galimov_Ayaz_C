#include <stdio.h>

int main() {
    char ch;
    printf("Введите символ: ");
    scanf(" %c", &ch);

    if (ch >= '0' && ch <= '9') {
        printf("Это цифра.\n");
    } 
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        printf("Это буква.\n");
    } 
    else {
        printf("Это другой символ.\n");
    }

    return 0;
}
