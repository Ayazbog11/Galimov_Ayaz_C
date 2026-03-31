#include <stdio.h>

struct Rectangle {
    float width;
    float height;
};

// Функция вычисления площади (передача по значению)
float areaByValue(struct Rectangle rect) {
    return rect.width * rect.height;
}

// Функция вычисления периметра (передача по значению)
float perimeterByValue(struct Rectangle rect) {
    return 2 * (rect.width + rect.height);
}

// Функция вычисления площади (передача по указателю)
float areaByPointer(const struct Rectangle *rect) {
    return rect->width * rect->height;
}

// Функция вычисления периметра (передача по указателю)
float perimeterByPointer(const struct Rectangle *rect) {
    return 2 * (rect->width + rect->height);
}

// Функция, изменяющая размеры прямоугольника (требуется указатель)
void scaleRectangle(struct Rectangle *rect, float factor) {
    rect->width *= factor;
    rect->height *= factor;
}

int main() {
    struct Rectangle rect = {5.0, 3.0};

    printf("===========Задание 4: Структуры и функции ===========\n");
    printf("Исходный прямоугольник: %.1f x %.1f\n\n", rect.width, rect.height);

    // Передача по значению
    printf("Передача по значению:\n");
    printf("Площадь: %.2f\n", areaByValue(rect));
    printf("Периметр: %.2f\n\n", perimeterByValue(rect));

    // Передача по указателю
    printf("Передача по указателю:\n");
    printf("Площадь: %.2f\n", areaByPointer(&rect));
    printf("Периметр: %.2f\n\n", perimeterByPointer(&rect));

    // Изменение через указатель
    printf("Увеличиваем в 2 раза...\n");
    scaleRectangle(&rect, 2.0);
    printf("Новые размеры: %.1f x %.1f\n", rect.width, rect.height);
    printf("Новая площадь: %.2f\n", areaByPointer(&rect));

    return 0;
}