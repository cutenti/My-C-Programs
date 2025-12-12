#pragma once

/*Реализация стека через односвязный список.
Функции newStack, push, pop, peek, delete
*/

typedef struct CharNode {
    struct CharNode* next;
    char symbol;
} CharNode;

/*
Главная структура, хранит ссылку на первый элемент.
Нужна вне реализации, чтобы создавать новый стек (CharStack* newStack()).
*/
typedef struct {
    CharNode* head;
} CharStack;

/*
Функция newStack возвращает указатель на выделенную память с первой вершиной стека (NULL):
*/
CharStack* newStack();

/*
        В функцию push мы передаем сслыку на вершину стека и новый элемент (char):
*/
int push(CharStack*, char);

/*
В функцию pop передаем вершину стека и указатель, куда положить удаляемый элемент (сохраняем - удаляем):
*/
int pop(CharStack*, char*);

/*
В функцию peek передаем указатель на вершину и на память, куда кладем значение из вершины (сохраняем - не удаляем):
*/
int peek(CharStack*, char*);

/*
В функцию delete передаем вершину, а функция удаляет все узлы и очищает память, ничего не возвращает:
*/
void deleteStack(CharStack*);
