#pragma once

/*
Определение структуры узла.
*/
typedef struct ListNode{
    struct ListNode* next;
    int data;
}ListNode;

/*
Определение структуры односвязного списка.
*/
typedef struct List{
    ListNode* head;
    ListNode* tail;
    int count;
}List;

/*
Функция проверки списка на пустоту.
*/
int isEmpty(List*);

/*
Функция создания пустого списка.
*/
List* newList(void);

/*
Функция вывода всех элементов списка.
*/
void printList(List*);

/*
Функция добавления значения в список по значению.
*/
int insert(List*, int);

/*
Функция прохода по кругу длины n и удаления каждого m-го элемента.
*/
int circle(int, int);

/*
Функция удаления списка и полного очищения памяти.
*/
void deleteList(List*);
