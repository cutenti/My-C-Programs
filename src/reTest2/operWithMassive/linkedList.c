#include "linkedList.h"
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
    newList->size = 0;

    return newList;
}

int insert(List* list, int value, int index)
{
    if (index < 0) {
        printf("ОШИБКА: отрицательный индекс\n");
        return 1;
    }

    ListNode* newNode = malloc(sizeof(ListNode));
    if (!newNode) {
        return 1;
    };
    newNode->data = value;

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
        list->size += 1;
        return 0;
    }

    if (isEmpty(list)) { // lля индекса > 0 список не должен быть пустым
        free(newNode);
        printf("ОШИБКА: нельзя вставить по индексу > 0 в пустой список\n");
        return 1;
    }

    ListNode* prev = list->head;
    for (int i = 1; i < index; i++) { // Ищем элемент ПЕРЕД нужной позицией
        if (prev->next == NULL) {
            free(newNode);
            printf("ОШИБКА: индекс %d превышает длину списка\n", index);
            return 1;
        }
        prev = prev->next;
    }

    newNode->next = prev->next;
    prev->next = newNode;
    list->size += 1;
    return 0;
}

int get(List* list, int* element, int index)
{
    if (index < 0) {
        printf("ОШИБКА: индекс не может быть отрицательным\n");
        return 1;
    }

    if (!list) {
        printf("ОШИБКА: Списка не существует\n");
        return 1;
    }
    if (list->head == NULL) {
        printf("ОШИБКА: Список пуст\n");
        return 1;
    }

    ListNode* currNode = list->head; // узел с индексом 0, с него начинаем проход до нужного индекса
    for (int i = 1; i <= index; i++) { // проходим по списку, ищем нужный индекс
        if (currNode->next == NULL) {
            printf("ОШИБКА: В списке меньше элементов, чем индекс, который указан в get\n");
            return 1;
        }

        currNode = currNode->next; // номер каждой итерации будет совпадать с номером текущего указателя
    }
    *element = currNode->data; // тогда последний полученный указатель -- нужный

    return 0;
}

int removeElement(List* list, int index)
{
    if (index < 0) {
        printf("ОШИБКА: индекс не может быть отрицательным\n");
        return 1;
    }

    if (!list) {
        printf("ОШИБКА: списка не существует\n");
        return 1;
    }

    if (!list->head) { // если head ни на что не ссылается, значит в списке нет элементов
        printf("Список пуст, не удается удалить элемент по индексу\n");
        return 1;
    } else {
        ListNode* currNode = list->head; // узел с индексом 0, с него начинаем проход до нужного индекса

        if (index == 0) { // если нужно удалить первый элемент - перекидываем head на второй элемент
            ListNode* deleteNode = currNode;
            list->head = list->head->next;
            free(deleteNode);
            list->size--;
            return 0;
        } else {
            for (int i = 1; i <= index - 1; i++) { // идем до элемента, предыдущего удаляемому
                if (currNode->next == NULL) {
                    printf("ОШИБКА: не удается remove элемент с индексом %d\n", index);
                    return 1;
                }
                currNode = currNode->next; // номер каждой итерации будет совпадать с номером текущего указателя
            }
            ListNode* deleteNode = currNode->next; // тк остановились на индекс ниже, то удаляемый элемент - следующий
            currNode->next = currNode->next->next; // перекидываем ссылку с пред-удаляемого на после-удаляемый

            free(deleteNode);
            list->size--;

            return 0;
        }
    }
}

int arithmeticMean(List* list)
{
    if (!list) {
        printf("Списка не существует\n");
    } else {
        if (list->head == NULL) {
            printf("Список пуст\n");
            return 0;
        } else {
            int summ = 0;
            ListNode* currNode = list->head; // первый узел для прохода
            while (currNode != NULL) {
                summ += currNode->data;
                currNode = currNode->next; // выводим элемен, кидаем ссылку на следующий. так пока не дойдем до последнего, который ссылается на NULL
            }
            return (float)summ/list->size;
        }
    }
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
            printf("\n");
            while (currNode != NULL) {
                printf("%d\t", currNode->data);
                currNode = currNode->next; // выводим элемен, кидаем ссылку на следующий. так пока не дойдем до последнего, который ссылается на NULL
            }
            printf("\n");
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