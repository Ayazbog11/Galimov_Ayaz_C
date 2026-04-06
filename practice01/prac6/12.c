#include <stdio.h>
int main() {
    char s12[] = "I love you";
    int len12 = sizeof(s12) - 1;
    int start = 0;
    for (int i = 0; i <= len12; i++) {
        if (s12[i] == ' ' || s12[i] == '\0') {
            int end = i - 1;
            while (start < end) {
                char t = s12[start];
                s12[start] = s12[end];
                s12[end] = t;
                start++;
                end--;
            }
        start = i + 1;
        }
    }
    printf("%s", s12);
}
