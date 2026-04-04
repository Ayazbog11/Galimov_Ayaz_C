#include "person.h"
#include <direct.h>  

// Проверка и создание папки data
void check_data_dir(void) {
    _mkdir("data");  
}

// Добавление расширения если нет
void fix_extension(char *filename, int is_binary) {
    if (strchr(filename, '.') == NULL) { // Если нет точки, значит нет расширения
        strcat(filename, is_binary ? ".bin" : ".txt"); // Добавляем .bin для бинарного формата, .txt для текстового
    }
}
// Сохранение в файл (текстовый или бинарный)
void save_to_file(void) {
    if (count == 0) {
        printf("No data to save!\n");
        return;
    }
    
    check_data_dir();  // Убедимся, что папка для данных существует
    // Получаем имя файла и формат от пользователя
    char filename[100];
    char path[120];    
    int choice;
    printf("Choose format:\n1. Binary (fwrite/fread)\n2. Text\nChoice: ");
    scanf("%d", &choice);
    clear_input_buffer(); // Очистка буфера после чтения числа
    
    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin); // Чтение имени файла с пробелами
    filename[strcspn(filename, "\n")] = 0; // Удаление символа новой строки
    
    fix_extension(filename, choice == 1);  // Добавляем расширение если нет
    sprintf(path, "data/%s", filename);    // Путь: data/имяфайла.txt
    
    if (choice == 1) { // Сохранение в бинарный файл
        save_binary(path);
    } else { // Сохранение в текстовый файл
        FILE *fp = fopen(path, "w");       // Открываем для записи
        if (!fp) {
            printf("Error opening file for writing!\n"); // Проверка успешного открытия файла
            return;
        }
        for (int i = 0; i < count; i++) { // Запись данных в текстовом формате
            fprintf(fp, "%s %d %.2f %d\n", people[i].name, people[i].age,  // Запись: имя возраст рост год_рождения
                    people[i].height, people[i].birth_year);
        }
        fclose(fp); // Закрываем файл
        printf("Saved %d records to text file '%s'.\n", count, path); // Сообщаем пользователю об успешном сохранении
    }
}
// Сохранение в бинарный файл
void save_binary(const char *filename) {
    FILE *fp = fopen(filename, "wb"); // Открываем файл для записи в бинарном режиме
    if (!fp) { // Проверка успешного открытия файла
        printf("Error opening file for writing!\n");
        return;
    }
    
    fwrite(&count, sizeof(int), 1, fp); // Сначала записываем количество записей, чтобы при загрузке знать сколько читать
    fwrite(people, sizeof(Person), count, fp); // Записываем массив структур Person в бинарном формате
    fclose(fp);
    printf("Saved %d records to binary file '%s'.\n", count, filename); // Сообщаем пользователю об успешном сохранении
}
// Загрузка из файла (текстовый или бинарный)
void load_from_file(void) {
    check_data_dir(); // Убедимся, что папка для данных существует
    // Получаем имя файла и формат от пользователя
    char filename[100];
    char path[120];
    int choice;
    // Запрос формата и имени файла для загрузки
    printf("Choose format:\n1. Binary\n2. Text\nChoice: "); 
    scanf("%d", &choice);
    clear_input_buffer();
    
    printf("Enter filename: "); 
    fgets(filename, sizeof(filename), stdin); // Чтение имени файла с пробелами
    filename[strcspn(filename, "\n")] = 0; // Удаление символа новой строки
    
    fix_extension(filename, choice == 1); // Добавляем расширение если его нет
    sprintf(path, "data/%s", filename);  // Формируем полный путь к файлу
    
    if (choice == 1) { // Загрузка из бинарного файла
        load_binary(path);
    } else {
        FILE *fp = fopen(path, "r"); // Открываем файл для чтения в текстовом режиме
        if (!fp) {
            printf("Error opening file '%s'!\n", path); // Проверка успешного открытия файла
            return;
        }
        
        count = 0; // Сброс текущего количества записей перед загрузкой новых данных
        
        Person p; // Временная переменная для чтения данных из файла
        while (fscanf(fp, "%49s %d %f %d", p.name, &p.age, &p.height, &p.birth_year) == 4) { // Чтение данных в формате: имя возраст рост год_рождения
            if (count >= capacity) { // Проверка необходимости расширения массива
                capacity = (capacity == 0) ? 2 : capacity * 2; // Увеличиваем емкость (двойной размер или начинаем с 2)
                people = realloc(people, capacity * sizeof(Person)); // Перераспределение памяти для массива структур Person
                if (!people) { // Проверка успешного выделения памяти
                    printf("Memory allocation failed!\n");
                    fclose(fp);
                    exit(1);
                }
            }
            people[count++] = p; // Добавляем прочитанную структуру Person в массив и увеличиваем счетчик
        }
        fclose(fp);
        printf("Loaded %d records from text file '%s'.\n", count, path); // Сообщаем пользователю об успешной загрузке данных
    }
}
// Загрузка из бинарного файла
void load_binary(const char *filename) {
    FILE *fp = fopen(filename, "rb"); // Открываем файл для чтения в бинарном режиме
    if (!fp) {
        printf("Error opening file '%s' for reading!\n", filename); // Проверка успешного открытия файла
        return;
    }
    
    int new_count; // Временная переменная для хранения количества записей, прочитанных из файла
    if (fread(&new_count, sizeof(int), 1, fp) != 1) { // Чтение количества записей из файла, проверка успешности чтения
        printf("Error reading file header!\n");
        fclose(fp);
        return;
    }
    // Выделение памяти для нового массива структур Person на основе количества записей, прочитанных из файла
    Person *temp = malloc(new_count * sizeof(Person));
    if (!temp) { // Проверка успешного выделения памяти
        printf("Memory allocation failed!\n");
        fclose(fp);
        return;
    }
    // Чтение массива структур Person из файла, проверка успешности чтения
    if (fread(temp, sizeof(Person), new_count, fp) != new_count) { // Если количество прочитанных записей не совпало с ожидаемым, значит произошла ошибка
        printf("Error reading data from file!\n");
        free(temp); // Освобождение временной памяти при ошибке чтения
        fclose(fp); // Закрытие файла
        return;
    }
    fclose(fp);
    
    free(people); // Освобождение старого массива данных перед заменой на новый
    people = temp; // Замена указателя на новый массив, загруженный из файла
    count = new_count; // Обновление счетчика записей на количество, прочитанное из файла
    capacity = new_count; // Установка емкости равной количеству, так как мы точно знаем, что столько записей есть в массиве
    printf("Loaded %d records from binary file '%s'.\n", count, filename); // Сообщаем пользователю об успешной загрузке данных
}