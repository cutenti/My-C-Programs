#include "sort.h"

#include <stdio.h>
#include <string.h>

int main()
{
    int array[100];
    int lenArray = 0;
    while (scanf("%d", &array[lenArray]) == 1) {
        lenArray++; // В конце считывания эта перемеенная хранит индекс последнего элемента массива
    }

    int copyArray[lenArray]; // Скопируем массив для конечного сравнения с отсортированным
    memcpy(copyArray, array, lenArray * sizeof(int));

    printf("Сортируемый массив чисел:\n");
    for (int i = 0; i < lenArray; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    quickSort(array, 0, lenArray - 1);

    printf("Отсортированный массив:\n");
    for (int i = 0; i < lenArray; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int count = 0; // Считаем количество чисел, изменивших место, для кода возврата
    for (int i = 0; i < lenArray; i++) {
        if (array[i] != copyArray[i]) {
            count += 1;
        }
    }
    return count;
}
