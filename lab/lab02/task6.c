#include <stdio.h> 
union Data {
    int i;
    float f;
    char c;
};
struct TypedData {
    union Data value;
    enum Type { TYPE_INT, TYPE_FLOAT, TYPE_CHAR } type;
};

void printTypedData(struct TypedData *td) {
    switch(td->type) {
        case TYPE_INT:
            printf("Integer: %d\n", td->value.i);
            break;
        case TYPE_FLOAT:
            printf("Float: %f\n", td->value.f);
            break;
        case TYPE_CHAR:
            printf("Char: '%c' (ASCII: %d)\n", td->value.c, td->value.c);
            break;
    }
}

int main() {
    union Data data;
    printf("===========Задание 6: Объединения (union)===========\n");
    printf("1. Присвоение int: 42\n");
    data.i = 42;
    printf("   data.i = %d\n", data.i);
    printf("   data.f = %e (интерпретация битов)\n", data.f);
    printf("   data.c = '%c' (интерпретация битов)\n", data.c);
    printf("\n2. Присвоение float: 3.14\n");
    data.f = 3.14;
    printf("   data.i = %d \n", data.i);
    printf("   data.f = %f\n", data.f);
    printf("   data.c = '%c'\n", data.c);
    printf("\n3. Присвоение char: 'A'\n");
    data.c = 'A';
    printf("   data.i = %d (65 - ASCII код 'A')\n", data.i);
    printf("   data.f = %e (интерпретация битов)\n", data.f);
    printf("   data.c = '%c'\n", data.c);
    printf("\n--- Демонстрация перезаписи памяти ---\n");
    data.i = 1000;
    printf("После data.i = 1000: i=%d\n", data.i);
    data.f = 3.14;
    printf("После data.f = 3.14: f=%f, i=%d (испорчено)\n", data.f, data.i);
    printf("\nРазмер union Data: %zu байт\n", sizeof(union Data));
    printf("Размер int: %zu байт\n", sizeof(int));
    printf("Размер float: %zu байт\n", sizeof(float));
    printf("Размер char: %zu байт\n", sizeof(char));
    printf("\n--- Типизированное объединение ---\n");

    struct TypedData td1, td2, td3;

    td1.type = TYPE_INT;
    td1.value.i = 123;

    td2.type = TYPE_FLOAT;
    td2.value.f = 2.718;

    td3.type = TYPE_CHAR;
    td3.value.c = 'Z';

    printf("td1: "); printTypedData(&td1);
    printf("td2: "); printTypedData(&td2);
    printf("td3: "); printTypedData(&td3);

    return 0;
}