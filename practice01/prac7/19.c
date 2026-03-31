#include <stdio.h>
void reverse_range(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int reverse_words(char *str) {
    char *start = str;
    char *end = str;
    char *word_start = str;
    while (*end) {
        end++;
        if (*end == ' ' || *end == '\0') {
            reverse_range(word_start, end - 1);
            word_start = end + 1;
        }
    }
    end--; 
    reverse_range(str, end);

    return 0;
}

int main() {
    char str[] = "hello world";
    printf("До: %s\n", str);
    reverse_words(str);
    printf("После: %s\n", str);
    return 0;
}
