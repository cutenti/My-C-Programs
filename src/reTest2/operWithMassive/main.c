#include "insertSort.h"
#include "linkedList.h"
#include <stdio.h>

int main()
{
    List* list = newList();
    int operation = -1;
    int value;

    while (operation != 0) {
        printf("Введите номер операции:\n0 Выйти\n1 Добавить значение\n2 Удалить значение\n3 Вывести список\n");
        scanf("%d", &operation);
        if (operation == 1) { // не знаю как рандом использовать пока
            insert(list, 54, 0);
            insert(list, 98, 0);
            insert(list, 46, 0);
            insert(list, 4, 0);
            insert(list, 80, 0);
            insert(list, 25, 0);
        } else if (operation == 2) {
            sort(list);
        } else if (operation == 3) {
            // не успела дописать
        } else if (operation == 4){
            arithmeticMean(list);
        } else if (operation == 5){ // чтобы его вывести
            printList(list);
        } else if (operation != 0) {
            printf("Вы ввели некорректное значение\n");
        }
    }
    deleteList(list);
    return 0;
}