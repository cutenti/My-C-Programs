#pragma once

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;
/*
Определение структуры узла.
*/

typedef struct List {
    ListNode* head;
} List;
/*
Определение структуры односвязного списка.
*/

int isEmpty(List*);
/*
Функция проверки списка на пустоту.
*/

List* newList(void);
/*
Функция создания пустого списка.
*/

int insert(List*, int);
/*
Функция добавления значения в отсортированный список.
*/

int removeElement(List*, int);
/*
Функция удаления значения из списка.
*/

void printList(List*);
/*
Функция вывода всех элементов списка.
*/

void deleteList(List*);
/*
Функция удаления списка и полного очищения памяти.
*/

int checkPairs(List*);