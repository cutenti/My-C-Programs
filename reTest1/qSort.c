#include <stdlib.h>
#include "qSort.h"

void quickSort(int* numbers, int left, int right)
{
    int pivot;
    int index;
    int lHold = left;
    int rHold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] > pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] < pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    index = left; 
    left = lHold;
    right = rHold;
    if (left < index)
        quickSort(numbers, left, index - 1);
    if (right > index)
        quickSort(numbers, index + 1, right);
}
