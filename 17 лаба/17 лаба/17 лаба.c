//17 лаба
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100 // Размер массива по умолчанию (можно изменить)

// Прототипы функций
void sort_bubble(int* ptrarr, int n);
void sort_shaker(int* ptrarr, int n);
void sort_select(int* ptrarr, int n);
void sort_insert(int* ptrarr, int n);
int* full_array(int* ptrarr, int n);
void put_array(int* ptrarr, int n);

int main() {
    setlocale(LC_CTYPE, "RUS");
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    // Динамическое выделение памяти для массива
    int* ptrarr = (int*)malloc(size * sizeof(int));

    if (!ptrarr) {
        printf("не получилось выделить память\n");
        return 1;
    }

    // Формирование массива
    printf("\nмассив:\n");
    full_array(ptrarr, size);
    put_array(ptrarr, size);

    // 1. Пузырьковая сортировка
    full_array(ptrarr, size);
    clock_t t = clock();
    sort_bubble(ptrarr, size);
    double time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("\nпузырьковая:\n");
    put_array(ptrarr, size);
    printf("пузырьковая время: %.6f \n", time);

    // 2. Шейкерная сортировка
    full_array(ptrarr, size);
    t = clock();
    sort_shaker(ptrarr, size);
    time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("\nшейкерная:\n");
    put_array(ptrarr, size);
    printf("шейкерная время: %.6f \n", time);

    // 3. Сортировка простым выбором
    full_array(ptrarr, size);
    t = clock();
    sort_select(ptrarr, size);
    time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("\nпростым выбором:\n");
    put_array(ptrarr, size);
    printf("простым выбором время: %.6f\n", time);

    // 4. Сортировка вставками
    full_array(ptrarr, size);
    t = clock();
    sort_insert(ptrarr, size);
    time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("\nвставками:\n");
    put_array(ptrarr, size);
    printf("вставками время: %.6f \n", time);

    // Освобождение памяти
    free(ptrarr);

    return 0;
}

// Пузырьковая сортировка
void sort_bubble(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ptrarr[j] > ptrarr[j + 1]) {
                int temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
    }
}

// Шейкерная (перемешивающая) сортировка
void sort_shaker(int* ptrarr, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (ptrarr[i] > ptrarr[i + 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i + 1];
                ptrarr[i + 1] = temp;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (ptrarr[i] < ptrarr[i - 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i - 1];
                ptrarr[i - 1] = temp;
            }
        }
        left++;
    }
}

// Сортировка простым выбором
void sort_select(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (ptrarr[j] < ptrarr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = ptrarr[i];
            ptrarr[i] = ptrarr[min_index];
            ptrarr[min_index] = temp;
        }
    }
}

// Сортировка вставками
void sort_insert(int* ptrarr, int n) {
    for (int i = 1; i < n; i++) {
        int current = ptrarr[i];
        int j = i - 1;
        while (j >= 0 && ptrarr[j] > current) {
            ptrarr[j + 1] = ptrarr[j];
            j--;
        }
        ptrarr[j + 1] = current;
    }
}

// Функция для генерации массива случайных чисел
int* full_array(int* ptrarr, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        ptrarr[i] = rand() % 100; // Случайное число от 0 до 99
    }
    return ptrarr;
}

// Функция для вывода массива на экран
void put_array(int* ptrarr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", ptrarr[i]);
    }
    printf("\n");
}
