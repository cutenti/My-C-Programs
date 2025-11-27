#include "sort.h"

#include <stdio.h>
#include <string.h>

int main()
{
    int buff[100];
    int index = 0;
    while (scanf("%d", &buff[index]) == 1) {
        index++;
    }

    int lenArray = index;
    int array[lenArray]; //Скопируем все введенные значения в массив без лишних нулей в конце
    for (int i = 0; i < lenArray; i++) {
        array[i] = buff[i];
    }

    int copyArray[lenArray]; //Скопируем массив для конечного сравнения с отсортированным
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

    int count = 0; //Считаем количество чисел, изменивших место, для кода возврата
    for (int i = 0; i < lenArray; i++) {
        if (array[i] != copyArray[i]) {
            count += 1;
        }
    }
    return count;
}
