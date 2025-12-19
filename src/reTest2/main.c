#include "linkedList.h"
#include "insertSort.h"

int main()
{
    List* list = newList();
    insert(list, 1, 0);
    insert(list, 2, 0);
    insert(list, 3, 0);
    insert(list, 6, 0);
    insert(list, 9, 0);
    insert(list, 4, 0);

    printList(list);

    sort(list);
    printList(list);

    deleteList(list);
    return 0;
}