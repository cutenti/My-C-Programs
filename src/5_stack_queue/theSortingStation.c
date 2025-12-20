#include "Stack.h"
#include <stdio.h>
#include <string.h>

void PostfixNotation(const char*);
int isOperator(char);
int isPriorityOperator(char);

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
    CharStack* stack = newStack(); // создаем стек с операторами и скобками

    int lenInfix = strlen(infix); // для перебора сохраняем длину выражения
    char postfix[200] = ""; // создаем пустую строку для постфиксного выражения
    char lastOper = '\0';
    char current;

    for (int i = 0; i < lenInfix; i++) {
        current = infix[i]; // текущий исследуемый элемент - current

        if (stack->head != NULL) {
            peek(stack, &lastOper); // "снимаем" последний добавленный в стек оператор (скобку)
        }
        if (strchr("1234567890", current)) { // если текущий элемент цифра
            char toAdd[2] = { current, '\0' };
            strcat(postfix, toAdd); // рисуем в конец постфиксного выражения
        } else if (current == '(') { // если открывающая скобка
            push(stack, current); // кладем её на стек
        } else if (isOperator(current)) {
            if (isPriorityOperator(current)) {
                push(stack, current); // тоже кладем на стек (разделим для красоты)
            } else {
                while (stack->head != NULL && strchr("*+-/", lastOper)) { // пока на стеке оператор
                    pop(stack, &lastOper); // снимаем его и переносим в постфиксное выражение
                    char toAdd[2] = { lastOper, '\0' };
                    strcat(postfix, toAdd);
                    // Обновляем lastOper после pop
                    if (stack->head != NULL) {
                        peek(stack, &lastOper);
                    } else {
                        lastOper = '\0';
                    }
                }
                push(stack, current);
            }
        } else if (current == ')') { // если закрывающая скобка, то
            while (stack->head != NULL && (lastOper != '(')) { // пока не встретим открывающую скобку
                pop(stack, &lastOper); // снимаем по оператору и кладем в конец постфикса
                char toAdd[2] = { lastOper, '\0' };
                strcat(postfix, toAdd);
                if (stack->head != NULL) {
                    peek(stack, &lastOper);
                }
            }
            if (stack->head != NULL && lastOper == '(') {
                pop(stack, &lastOper); // убираем открывающую скобку
            }
        }
    }

    int lenPostfix = strlen(postfix);
    while (stack->head != NULL) { // пока стек имеет операторы - снимаем в конец постфикса
        pop(stack, &lastOper);
        postfix[lenPostfix++] = lastOper;
    }
    postfix[lenPostfix] = '/0';

    printf("\n%s\n\n", postfix);
}

int isOperator(char symbol)
{
    return strchr("*/-+", symbol) ? 1 : 0;
}

int isPriorytyOperator(char symbol)
{
    return strchr("*/", symbol) ? 1 : 0;
}
