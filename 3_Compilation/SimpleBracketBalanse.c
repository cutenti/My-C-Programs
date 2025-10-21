#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int balance(char*, char, char);

int main(void)
{
    printf("Введите через enter виды открывающей и закрывающей скобки, на баланс которых мы будем проверять строку\n");
    char open;
    char close;
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%c", &open);
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%c", &close);

    printf("Введите проверяемую строку:\n");
    char stringCheck[200];
    fgets(stringCheck, 200, stdin);
    stringCheck[strcspn(stringCheck, "\n")] = '\0';

    int result = balance(stringCheck, open, close);
    if (result == 0)
        printf("Во введенной строке НЕ соблюдается баланс скобок\n");
    else
        printf("Во введенной строке соблюдается баланс скобок\n");
}

int balance(char* stringCheck, char open, char close)
{
    int countOpen = 0;
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
