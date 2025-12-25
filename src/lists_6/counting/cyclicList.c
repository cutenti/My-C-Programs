#include "cyclicList.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty(List* list)
{
    return list->count == 0;
}

List* newList(void)
{
    List* newList = malloc(sizeof(List));
    if (!newList) {
        printf("ОШИБКА выделения памяти\n");
        return NULL;
    }

    newList->head = NULL;
    newList->tail = NULL;
    newList->count = 0;

    return newList;
}

void printList(List* list)
{
    if (!list) {
        printf("Списка не существует\n");
    } else {
        if (list->count == 0) {
            printf("Список пуст\n");
        } else {
            ListNode* currNode = list->head; // первый узел для прохода
            printf("\n");
            for (int i = 0; i < list->count; i++) {
                printf("%d\t", currNode->data);
                currNode = currNode->next; // выводим элемен, кидаем ссылку на следующий. так пока не дойдем до последнего, который ссылается на NULL
            }
            printf("\n");
        }
    }
}

int insert(List* list, int value)
{
    ListNode* newNode = malloc(sizeof(ListNode));
    if (!newNode) {
        printf("Ошибка выделения памяти\n");
        return 1;
    };
    newNode->data = value;

    if (isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
        list->count++;
        return 0;
    }

    newNode->next = list->head;
    list->tail->next = newNode;
    list->head = newNode;
    list->count++;

    return 0;
}

int circle(int n, int m)
{
    List* list = newList();
    for (int i = n - 1; i >= 0; i--) {
        insert(list, i);
    }

    int k = 0;

    ListNode* toKill = list->head;

    while (list->count > 1) {
        k++;

        if (k == m - 1){
            list->tail = list->head;
        } else if (k == m) {
            printf("Killed sicarium of number %d\n", list->head->data);
            toKill = list->head;

            list->tail->next = list->head->next;

            list->count--;
            list->head = toKill->next;

            free(toKill);

            k = 0;
            continue;
        }
        list->head = list->head->next;
    }

    int result = list->head->data;
    deleteList(list);
    return result;
}

void deleteList(List* list)
{
    if (list) {
        ListNode* deleteNode;

        while (list->count) {
            deleteNode = list->head;
            list->head = list->head->next;
            list->count--;
            free(deleteNode);
        }
        free(list);
        list = NULL;
    }
}
