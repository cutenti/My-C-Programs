#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct listNode{
    int value;
    struct listNode* next;
}listNode;

typedef struct List{
    listNode* tail;
    int size;
}List;

int insert(List* list, int number){
    listNode* newNode = malloc(sizeof(listNode));
    if (!newNode) {return 1;}
    
    if (list->tail == NULL){
        newNode->value = number;
	newNode->next = newNode;
	list->size = 1;
	list->tail = newNode;
    } else {
        newNode->value = number;
        newNode->next = list->tail->next;
        list->tail->next = newNode;
	list->size += 1;
    }
    return 0;
}

List* newList(void){
    List* list = malloc(sizeof(List));
    if (!list) {return NULL;}
    list->tail = NULL;
    list->size = 0;
    return list;
}

/*int main(void){
    List* list = newList();
    insert(list, 10);
    printf("Начало: %d, Конец: %d, Длина: %d\n", list->tail->next->value, list->tail->value, list->size);
     insert(list, 20);
     printf("Начало: %d, Конец: %d, Длина: %d\n", list->tail->next->value, list->tail->value, list->size);
    return 0;
}*/
