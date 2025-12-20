#include "linkedList.h"
#include <stdio.h>

int sort(List* list)
{
    if (!list) {
        printf("Список не передан\n");
        return 1;
    }

    if (list->size == 0) {
        printf("Список пуст\n");
        return -1;
    }

    if (list->size == 1) {
        printf("Список из 1 элемента, уже отсортирован\n");
        return 0;
    }

    ListNode* currNode = list->head;
    ListNode* nextNode = currNode->next;
    ListNode* sortNode = list->head;

    while (currNode->next) { // пока не дошли до конца списка
        nextNode = currNode->next;

        if (currNode->data > nextNode->data) {
            sortNode = list->head; // чтобы пройти список с начала и найти куда вставить

            if (sortNode->data > nextNode->data) { // если первый элемент больше вставляемого
                currNode->next = nextNode->next; // в изначальной цепи удаляем эл-т
                nextNode->next = list->head;
                list->head = nextNode;
            } else {
                while (sortNode->next->data < nextNode->data) { // перебираем пока след. не будет >= вставляемого
                    if (!sortNode->next) {
                        break;
                    } // если дошли до конца
                    sortNode = sortNode->next;
                }
                currNode->next = nextNode->next; // в изначальной цепи удаляем эл-т
                nextNode->next = sortNode->next; // тк меняем место эл-та, то его next меняется
                //if (!sortNode->next) {
                    sortNode->next = nextNode; // и next эл-та, после которого вставляем тоже меняется
                //}
            }
        } else {
            currNode = currNode->next;
        }
    }
    return 0;
}
