#include "SumBinarNums.h"

int binarNumber(int number)
{
    int mask = 1;
    int resultSum = 0;
    for (int i = 0; i < 32; i++) {
        if (mask & number) {
            resultSum += 1;
        }
        mask <<= 1;
    }
    return resultSum;
}