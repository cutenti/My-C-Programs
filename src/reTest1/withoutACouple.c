#include <stdio.h>
#include "sortedLinkedList.h"
/*
Не доделала функцию checkPairs в односвзяном списке, остальные работают корректно
*/

int main(){
    int inputNum;

    List* sortedNumList = newList();

    printf("Введите натуральные числа через пробел, не больше 200, последним должен быть 0, и нажмите Enter\n");
    while (inputNum != 0){
        scanf("%d", &inputNum);
        if (inputNum){
            insert(sortedNumList, inputNum);
        }
    }
    printList(sortedNumList);
    checkPairs(sortedNumList);

    /*int allNums[200] = {0};
    int countNums;
    printf("Введите натуральные числа через пробел, не больше 200, последним должен быть 0, и нажмите Enter\n");
    for (int i = 0; i < 200; i++){
        scanf("%d", &inputNum);
        if (inputNum != 0){
            allNums[i] = inputNum;
        } else {
            countNums = i;
            break; // считаем все, кроме нуля, тк 0 - флаг завершения
        }

    }
    quickSort(allNums, 0, countNums-1); // запускаем сортировку массива с начала до конца
    for (int i = 0; i < countNums; i++){
        printf("%d ", allNums[i]);
    }
    printf("\n");*/
    // попробуем отсортировать массив и пройтись по нему
    deleteList(sortedNumList);
    return 0;
}