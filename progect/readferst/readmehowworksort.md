# Как работает сортировка в проекте (qsort)

## Общий принцип qsort

`qsort` — это стандартная функция из `stdlib.h`, которая реализует алгоритм **быстрой сортировки (Quick Sort)**.

### Алгоритм Quick Sort:
1. **Выбираем опорный элемент** (pivot) из массива
2. **Разделяем** массив на две части:
   - Элементы меньше pivot — слева
   - Элементы больше pivot — справа
3. **Рекурсивно** повторяем для левой и правой части
4. **Базовый случай**: массив из 1 элемента уже отсортирован

**Сложность:** O(n log n) в среднем, O(n²) в худшем (редко)

---

## Как использовать qsort в C

```c
void qsort(
    void *base,      // Указатель на начало массива
    size_t nmemb,    // Количество элементов
    size_t size,     // Размер одного элемента в байтах
    int (*compar)(const void *, const void *)  // Функция сравнения
);
### 1. Функции сортировки (sort.c)

```c
#include "person.h"

// Компаратор для сортировки по имени (алфавитный порядок)
int compare_by_name(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return strcmp(p1->name, p2->name);
}

// Компаратор для сортировки по возрасту (числовой порядок)
int compare_by_age(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return p1->age - p2->age;
}

// Обёртка для сортировки по имени
void sort_by_name(void) {
    if (count < 2) {
        printf("Not enough records to sort!\n");
        return;
    }
    qsort(people, count, sizeof(Person), compare_by_name);
    printf("Sorted %d records by name (alphabetically).\n", count);
}

// Обёртка для сортировки по возрасту
void sort_by_age(void) {
    if (count < 2) {
        printf("Not enough records to sort!\n");
        return;
    }
    qsort(people, count, sizeof(Person), compare_by_age);
    printf("Sorted %d records by age.\n", count);
}