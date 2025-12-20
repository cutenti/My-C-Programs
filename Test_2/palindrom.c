#include <stdio.h>
#include "list.h"

int main(){
    List* list = newList();
    printf("Введите числа (Ctrl+D/Ctrl+Z для завершения):\n");
    int value;
    while (scanf("%d", &value) == 1) {
        insert(list, value);
    }
    printf("\nНачало: %d, Конец: %d, Длина: %d\n", list->tail->next->value, list->tail->value, list->size);

}

int checkPalindrom(List* list){
    listNode* top = list->tail;
    listNode* end = list->tail->next;
    for (int i=0; i <= (list->size)/2; i++){
        if (top->value != end->value) {return 0;}
	top = top->next;
	end = 
    }
}
