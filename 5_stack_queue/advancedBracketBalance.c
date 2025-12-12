#include "Stack.h" // подключаем наш заголовочный со стеком
#include <stdio.h>
#include <string.h>

int ParathesesBalance(const char*);

int main()
{
    char string[200]; // можно ли объявить строку через указатель неограниченного размера и туда считать?..
    int result;

    printf("Введите проверяемую строку:\n");
    fgets(string, 200, stdin);
    string[strcspn(string, "\n")] = '\0'; // удаляем '\n' по индексу.

    result = ParathesesBalance(string);
    if (!result) { // если успешно - функция вернет 0.
        printf("\nБаланс соблюден\n");
    } else {
        printf("\nБаланс НЕ соблюден\n");
    }
    return 0;
}

int ParathesesBalance(const char* string)
{
    CharStack* bracketStack = newStack();
    int lenString = strlen(string);

    for (int i = 0; i < lenString; i++) {
        char current = string[i]; // текущий анализируемый элемент строки
        if (current == '{' || current == '(' || current == '[') {
            push(bracketStack, current);
        } else if (current == '}' || current == ')' || current == ']') {
            char last; // последняя добавленная скобка в стек
            pop(bracketStack, &last); // удалим, раз уже закрывающая скобка на очереди. а там и проверим.

            if (!((current == '}' && last == '{') || (current == ']' && last == '[') || (current == ')' && last == '('))) {
                return 1; // значит тип закрывающей не совпал с типом открывающей, а это плохо.
            }
        }
    }
    if (!(bracketStack->head)) { // если head == NULL (нет элементов в стеке), то все скобки нашли пару.
        return 0;
    } else { // если осталась хоть одна скобка - баланса нет. (и любви)
        return 1;
    }
}