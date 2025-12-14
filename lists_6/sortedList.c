#include "linkedSortedList.h"
#include <stdio.h>

int main()
{
    List* sortedList = newList();
    int operation = -1;
    int value;

    while (operation != 0) {
        printf("Введите номер операции:\n0 Выйти\n1 Добавить значение\n2 Удалить значение\n3 Вывести список\n");
        scanf("%d", &operation);
        if (operation == 1) {
            printf("Введите значение:\n");
            scanf("%d", &value);
            insert(sortedList, value);
        } else if (operation == 2) {
            printf("Введите значение:\n");
            scanf("%d", &value);
            removeElement(sortedList, value);
        } else if (operation == 3) {
            printList(sortedList);
        } else if (operation != 0) {
            printf("Вы ввели некорректное значение\n");
        }
    }
}
