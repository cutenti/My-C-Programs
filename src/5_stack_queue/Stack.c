#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

CharStack* newStack(void)
{
    CharStack* stack = malloc(sizeof(CharStack));
    if (!stack)
        return NULL;
    stack->head = NULL;
    return stack;
}

int push(CharStack* stack, char element)
{
    CharNode* newNode = malloc(sizeof(CharNode));
    if (!newNode)
        return -1;
    newNode->symbol = element;

    newNode->next = stack->head;

    stack->head = newNode;
    return 0;
}

int pop(CharStack* stack, char* outElement)
{
    if (stack->head == NULL)
        return 1;

    CharNode* nodeToRemove = stack->head;

    *outElement = nodeToRemove->symbol;

    stack->head = nodeToRemove->next;

    free(nodeToRemove);
    return 0;
}

int peek(CharStack* stack, char* topElement)
{
    if (!stack)
        return -1;
    *topElement = stack->head->symbol;
    return 0;
}

void deleteStack(CharStack* stack)
{
    CharNode* current = stack->head;
    while (current != NULL) {
        CharNode* to_delete = current;
        current = current->next;
        free(to_delete); // освобождение памяти
    }
    free(stack);
}
