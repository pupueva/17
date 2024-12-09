//17 ����
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100 // ������ ������� �� ��������� (����� ��������)

// ��������� �������
void sort_bubble(int* ptrarr, int n);
void sort_shaker(int* ptrarr, int n);
void sort_select(int* ptrarr, int n);
void sort_insert(int* ptrarr, int n);
int* full_array(int* ptrarr, int n);
void put_array(int* ptrarr, int n);

int main() {
    setlocale(LC_CTYPE, "RUS");
    int size;
    printf("������� ������ �������: ");
    scanf("%d", &size);

    // ������������ ��������� ������ ��� �������
    int* ptrarr = (int*)malloc(size * sizeof(int));

    if (!ptrarr) {
        printf("�� ���������� �������� ������\n");
        return 1;
    }

    // ������������ �������
    printf("\n������:\n");
    full_array(ptrarr, size);
    put_array(ptrarr, size);

    // 1. ����������� ����������
    full_array(ptrarr, size);
    clock_t t = clock();
    sort_bubble(ptrarr, size);
    double time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("\n�����������:\n");
    put_array(ptrarr, size);
    printf("����������� �����: %.6f \n", time);

    // 2. ��������� ����������
    full_array(ptrarr, size);
    t = clock();
    sort_shaker(ptrarr, size);
    time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("\n���������:\n");
    put_array(ptrarr, size);
    printf("��������� �����: %.6f \n", time);

    // 3. ���������� ������� �������
    full_array(ptrarr, size);
    t = clock();
    sort_select(ptrarr, size);
    time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("\n������� �������:\n");
    put_array(ptrarr, size);
    printf("������� ������� �����: %.6f\n", time);

    // 4. ���������� ���������
    full_array(ptrarr, size);
    t = clock();
    sort_insert(ptrarr, size);
    time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("\n���������:\n");
    put_array(ptrarr, size);
    printf("��������� �����: %.6f \n", time);

    // ������������ ������
    free(ptrarr);

    return 0;
}

// ����������� ����������
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

// ��������� (��������������) ����������
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

// ���������� ������� �������
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

// ���������� ���������
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

// ������� ��� ��������� ������� ��������� �����
int* full_array(int* ptrarr, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        ptrarr[i] = rand() % 100; // ��������� ����� �� 0 �� 99
    }
    return ptrarr;
}

// ������� ��� ������ ������� �� �����
void put_array(int* ptrarr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", ptrarr[i]);
    }
    printf("\n");
}
