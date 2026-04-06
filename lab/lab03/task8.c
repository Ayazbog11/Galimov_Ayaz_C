/* Задание 8: Динамический список с меню */
#include <stdio.h>
#include <stdlib.h>

int *list;
int listSize = 0;
int listCapacity = 0;

void initList() {
    list = NULL;
    listSize = 0;
    listCapacity = 0;
}

void addElement() {
    int value;
    int *tmp;

    printf("Введите значение для добавления: ");
    scanf("%d", &value);

    if (list == NULL) {
        list = (int*)malloc(sizeof(int));
        if (list == NULL) {
            printf("Ошибка выделения памяти\n");
            return;
        }
        listCapacity = 1;
    }
    else if (listSize >= listCapacity) {
        listCapacity = listCapacity * 2;
        tmp = (int*)realloc(list, listCapacity * sizeof(int));
        if (tmp == NULL) {
            printf("Ошибка расширения памяти\n");
            return;
        }
        list = tmp;
    }

    list[listSize] = value;
    listSize++;
    printf("========== Элемент %d добавлен ==========\n", value);
}

void removeElement() {
    int index;
    int *tmp;
    int i;

    if (listSize == 0) {
        printf("Список пуст\n");
        return;
    }

    printf("Введите индекс для удаления (0-%d): ", listSize - 1);
    scanf("%d", &index);

    if (index < 0 || index >= listSize) {
        printf("Неверный индекс\n");
        return;
    }

    for (i = index; i < listSize - 1; i++) {
        list[i] = list[i + 1];
    }

    listSize--;

    if (listSize > 0) {
        tmp = (int*)realloc(list, listSize * sizeof(int));
        if (tmp != NULL) {
            list = tmp;
        }
    } else {
        free(list);
        list = NULL;
        listCapacity = 0;
    }

    printf("========== Элемент удален ==========\n");
}

void printList() {
    int i;

    if (listSize == 0) {
        printf("Список пуст\n");
        return;
    }

    printf("\n========== Список (%d элементов) ==========\n", listSize);
    for (i = 0; i < listSize; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void resizeList() {
    int newSize;
    int *tmp;
    int i;

    printf("Введите новый размер: ");
    scanf("%d", &newSize);

    if (newSize < 0) {
        printf("Размер не может быть отрицательным\n");
        return;
    }

    if (newSize == 0) {
        free(list);
        list = NULL;
        listSize = 0;
        listCapacity = 0;
        printf("========== Список очищен ==========\n");
        return;
    }

    tmp = (int*)realloc(list, newSize * sizeof(int));
    if (tmp == NULL && newSize > 0) {
        printf("Ошибка изменения размера\n");
        return;
    }

    list = tmp;

    if (newSize > listSize) {
        for (i = listSize; i < newSize; i++) {
            list[i] = 0;
        }
    }

    listSize = newSize;
    listCapacity = newSize;
    printf("========== Размер изменен на %d ==========\n", newSize);
}

void showMenu() {
    printf("\n");
    printf("=====================================\n");
    printf("========== ДИНАМИЧЕСКИЙ СПИСОК ==========\n");
    printf("=====================================\n");
    printf("========== 1. Добавить элемент ==========\n");
    printf("========== 2. Удалить элемент  ==========\n");
    printf("========== 3. Вывести список   ==========\n");
    printf("========== 4. Изменить размер  ==========\n");
    printf("========== 0. Выход            ==========\n");
    printf("=====================================\n");
    printf("Выбор: ");
}

int main() {
    int choice;

    printf("========== Задание 8: Динамический список ==========\n");

    initList();

    do {
        showMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: addElement(); break;
            case 2: removeElement(); break;
            case 3: printList(); break;
            case 4: resizeList(); break;
            case 0: 
                printf("\n========== Освобождение памяти... ==========\n");
                if (list != NULL) {
                    free(list);
                    list = NULL;
                }
                printf("========== До свидания! ==========\n");
                break;
            default: printf("Неверный выбор!\n");
        }
    } while (choice != 0);

    return 0;
}
