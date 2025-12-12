#include "Stack.h"
#include <stdio.h>
#include <string.h>

void PostfixNotation(const char*);

int main()
{
    char infixNotation[200];
    printf("Введите выражение в инфиксном представлении:\n");
    fgets(infixNotation, 200, stdin);
    infixNotation[strcspn(infixNotation, "\n")] = '\0';

    PostfixNotation(infixNotation);
    return 0;
}

void PostfixNotation(const char* infix)
{
    CharStack* queue = newStack(); // создаем стек с операторами и скобками

    int lenInfix = strlen(infix); // для перебора сохраняем длину выражения
    char postfix[200] = "\0"; // создаем пустую строку для постфиксного выражения
    char lastOper = '\0';
    char current;

    for (int i = 0; i < lenInfix; i++) {
        current = infix[i]; // текущий исследуемый элемент - current

        if (queue->head != NULL){
            peek(queue, &lastOper); // "снимаем" последний добавленный в стек оператор (скобку)
        }
        if (strchr("1234567890", current)) { // если текущий элемент цифра
            char toAdd[2] = {current, '\0'};
            strcat(postfix, toAdd); // рисуем в конец постфиксного выражения
        } else if (current == '(') { // если открывающая скобка
            push(queue, current); // кладем её на стек
        } else if (strchr("*/", current)) { // если приоритетный оператор
            push(queue, current); // тоже кладем на стек (разделим для красоты)
        } else if (strchr("+-", current)) { // если не приоритетный оператор
            while (queue->head != NULL && strchr("*/+-", lastOper)) { // пока на стеке оператор
                pop(queue, &lastOper); // снимаем его и переносим в постфиксное выражение
                char toAdd[2] = {lastOper, '\0'};
                strcat(postfix, toAdd);
                // Обновляем lastOper после pop
                if (queue->head != NULL) {
                    peek(queue, &lastOper);
                } else {
                    lastOper = '\0';
                }
            }
            push(queue, current);
        } else if (current == ')') { // если закрывающая скобка, то
            while (queue->head != NULL && (lastOper != '(')) { // пока не встретим открывающую скобку
                pop(queue, &lastOper); // снимаем по оператору и кладем в конец постфикса
                char toAdd[2] = {lastOper, '\0'};
                strcat(postfix, toAdd);
                if (queue->head != NULL) {
                    peek(queue, &lastOper);
                }
            }
            if (queue->head != NULL && lastOper == '(') {
                pop(queue, &lastOper); // убираем открывающую скобку
            }
        }
    }
    while (queue->head != NULL) { // пока стек имеет операторы - снимаем в конец постфикса
        pop(queue, &lastOper);
        char toAdd[2] = {lastOper, '\0'};
        strcat(postfix, toAdd);
    }
    printf("\n%s\n\n", postfix);
}
