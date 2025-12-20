#include "sortedLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty(List* list)
{
    return list->head == NULL;
}

List* newList(void)
{
    List* newList = malloc(sizeof(List));
    if (!newList) {
        printf("ОШИБКА выделения памяти\n");
        return NULL;
    }

    newList->head = NULL;

    return newList;
}

void printList(List* list)
{
    if (!list) {
        printf("Списка не существует\n");
    } else {

        if (list->head == NULL) {
            printf("Список пуст\n");
        } else {
            ListNode* currNode = list->head; // первый узел для прохода
            printf("\nСписок:\n");
            while (currNode != NULL) {
                printf("%d\t", currNode->data);
                currNode = currNode->next; // выводим элемен, кидаем ссылку на следующий. так пока не дойдем до последнего, который ссылается на NULL
            }
            printf("\n\n");
        }
    }
}

void deleteList(List* list)
{
    if (list) { // если список существует
        ListNode* deleteNode;

        while (list->head) {
            deleteNode = list->head;
            list->head = list->head->next;
            free(deleteNode);
        }
        free(list);
        list = NULL;
    }
}

int insert(List* list, int value)
{
    ListNode* newNode = malloc(sizeof(ListNode));
    if (!newNode) {
        return 1;
    };
    newNode->data = value;

    if (isEmpty(list)) {
        list->head = newNode;
        return 0;
    }

    if (value <= list->head->data) {
        newNode->next = list->head;
        list->head = newNode;
        return 0;
    }

    ListNode* compareNode = list->head;
    int compareValue = compareNode->data;
    ListNode* prevNode = NULL;
    while (value > compareValue) {
        prevNode = compareNode;
        compareNode = compareNode->next;
        if (compareNode) {
            compareValue = compareNode->data;
        } else {
            break;
        }
    }
    prevNode->next = newNode;
    newNode->next = compareNode;

    return 0;
}

int removeElement(List* list, int value)
{
    if (!list) {
        printf("ОШИБКА: списка не существует\n");
        return 1;
    }

    if (!list->head) { // если head ни на что не ссылается, значит в списке нет элементов
        printf("Список пуст, не удается удалить элемент по индексу\n");
        return 1;
    }

    ListNode* deleteNode = list->head;
    int deleteValue = deleteNode->data;
    ListNode* prevNode = NULL;
    while (value != deleteValue) {
        prevNode = deleteNode;
        deleteNode = deleteNode->next;
        if (deleteNode) {
            deleteValue = deleteNode->data;
        } else {
            printf("ОШИБКА: элемент не найден\n");
            return 1;
        }
    }
    if (!prevNode) {
        list->head = deleteNode->next;
    } else {
        prevNode->next = deleteNode->next;
    }
    free(deleteNode);
    return 0;
}

int checkPairs(List* list)
{
    if (!list) {
        printf("Списка не существует\n");
        return 1;
    }

    if (list->head == NULL) {
        printf("Список пуст\n");
        return 1;
    }

    ListNode* currNode = list->head->next; // первый узел для прохода
    int currValue = currNode->data;
    int prevValue = list->head->data;
    int countSame = 1;
    int lastDiffValue = -1;

    printf("\nСписок без пары:\n");

    while (currNode != NULL) {
        if (prevValue + 1 == currValue) {
            prevValue = currValue;
            currValue = currNode->next->data;
            if (prevValue == currValue) {
            countSame += 1;
        }} else {
            printf("%d", prevValue);
            continue;
        }
        while (countSame > 1) {
            if (prevValue + 1 == currValue) {
                currValue = currNode->next->data;
                countSame -= 1;
            } else {
                countSame = 1;
                for (int k = 0; k < countSame - 1; k++) {
                    printf("%d\t", prevValue);
                }
            }
        }
        prevValue = currValue;
        currNode = currNode->next;
    }

    printf("\n\n");

    return 0;
}