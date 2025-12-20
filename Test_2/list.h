#pragma once

typedef struct listNode{
    int value;
    struct listNode* next;
}listNode;

typedef struct List{
    listNode* tail;
    int size;
}List;

int insert(List*, int);

List* newList(void);
