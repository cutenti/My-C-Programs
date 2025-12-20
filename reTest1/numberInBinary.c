#include <stdio.h>
#include "SumBinarNums.h"

int main(){
    int number1, number2;
    printf("Введите через пробел 2 числа и нажмите Enter\n");
    scanf("%d %d", &number1, &number2);

    int binar1 = binarNumber(number1);
    int binar2 = binarNumber(number2);

    if (binar1 > binar2){
        printf("Больше по сумме цифр в двоичной записи %d\n", number1);
    } else if (binar1 == binar2){
        printf("Чила равны\n");
    } else {
        printf("Больше по сумме цифр в двоичной записи %d\n", number2);
    }
    
    return 0;
}