#include <stdio.h>

int main() {
    char s11[] = "aaabbc";
    printf("11. Сжатие %s: ", s11);
    for (int i = 0; s11[i]; i++) {
        int count = 1;
        while (s11[i] == s11[i + 1]) { count++; i++; }
        printf("%c%d", s11[i], count);
    }
}