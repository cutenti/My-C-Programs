#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int balance(char*);

int main(void)
{
    printf("Введите проверяемую строку:\n");
    char stringCheck[200];
    fgets(stringCheck, 200, stdin);
    stringCheck[strcspn(stringCheck, "\n")] = '\0';
    int result = balance(stringCheck);
    if (result == 0)
        printf("Во введенной строке НЕ соблюдается баланс скобок\n");
    else
        printf("Во введенной строке соблюдается баланс скобок\n");
}

int balance(char* stringCheck)
{
    char open = '(';
    int countOpen = 0;
    char close = ')';
    int countClose = 0;
    for (int i = 0; i < strlen(stringCheck); i++) {
        if (stringCheck[i] == open)
            countOpen += 1;
        else if (stringCheck[i] == close)
            countClose += 1;
        if (countClose > countOpen) {
            return 0;
        }
    }
    if (countOpen == countClose)
        return 1;
    else
        return 0;
}
