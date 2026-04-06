#include <stdio.h>
char* find_substring(char *str, char *sub) {
    if (!*sub) return str; 

    char *p1, *p2, *p3;
    for (p1 = str; *p1 != '\0'; p1++) {
        p2 = p1;   
        p3 = sub;  
        while (*p2 != '\0' && *p3 != '\0' && *p2 == *p3) {
            p2++;
            p3++;
        }
        if (*p3 == '\0') {
            return p1;
        }
    }

    return NULL; 
}

int main() {
    char text[] = "Hello, world!";
    char pattern[] = "world";

    char *result = find_substring(text, pattern);

    if (result) {
        printf("Текст начиная с подстроки: %s\n", result);
    } else {
        printf("Подстрока не найдена.\n");
    }

    return 0;
}
