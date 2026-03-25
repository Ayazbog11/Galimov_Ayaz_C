#include <stdio.h>

int main() {
    char str[] = "Hello!! World!!!";
    char temp[100];
    int len = 0;

    // 1. Вывод посимвольно через указатель
    printf("1. Посимвольно: ");
    char *ptr = str;
    while (*ptr) {
        printf("%c ", *ptr++);
    }
    printf("\n");

    // 2. Длина строки 
    while (str[len] != '\0') len++;
    printf("2. Длина: %d\n", len);

    // 3. Задом наперёд 
    printf("3. Реверс: ");
    for (int i = len - 1; i >= 0; i--) printf("%c", str[i]);
    printf("\n");

    // 4. Замена гласных на '*'
    for (int i = 0; i <= len; i++) temp[i] = str[i]; 
    for (int i = 0; temp[i]; i++) {
        char c = temp[i];
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') {
            temp[i] = '*';
        }
    }
    printf("4. Гласные: %s\n", temp);

    // 5. Если больше трех «!» -> STOP
    int bang = 0;
    for (int i = 0; str[i]; i++) if (str[i] == '!') bang++;
    printf("5. Проверка !: ");
    if (bang > 3) printf("STOP\n"); else printf("OK\n");

    // 6. Вид hElLo WoRlD 
    for (int i = 0; i <= len; i++) temp[i] = str[i];
    for (int i = 0; temp[i]; i++) {
        if (i % 2 == 0) {
            if (temp[i] >= 'A' && temp[i] <= 'Z') temp[i] += 32; 
        } else {
            if (temp[i] >= 'a' && temp[i] <= 'z') temp[i] -= 32;
        }
    }
    printf("6. Регистр: %s\n", temp);

    char filtered[100];
    char toDel;
    int j = 0;

    printf("Введите символ для удаления: ");
    scanf(" %c", &toDel);

    for (int i = 0; str[i]; i++) {
        if (str[i] != toDel) {
            filtered[j++] = str[i];
        }
    }
    filtered[j] = '\0';
    printf("7. Без '%c': %s\n", toDel, filtered);

    // 8. Проверка пароля
    int need1 = 0, need2 = 0;
    char pass[] = "Pass123";
    for (int i = 0; pass[i]; i++) {
        if ((pass[i] >= 'a' && pass[i] <= 'z') || (pass[i] >= 'A' && pass[i] <= 'Z')) need1 = 1;
        if (pass[i] >= '0' && pass[i] <= '9') need2 = 1;
    }
    printf("8. Пароль %s: %s\n", pass, (need1 && need2) ? "Valid" : "Invalid");

    // 9. Одинаковые подряд
    int repeat = 0;
    for (int i = 0; str[i] && str[i+1]; i++) {
        if (str[i] == str[i+1]) repeat = 1;
    }
    printf("9. Подряд в '%s': %s\n", str, repeat ? "Да" : "Нет");

    // 10. Разделить пополам
    printf("10. Половины: ");
    int mid = len / 2;
    for (int i = 0; i < mid; i++) printf("%c", str[i]);
    printf(" | ");
    for (int i = mid; i < len; i++) printf("%c", str[i]);
    printf("\n");

    return 0;
}
