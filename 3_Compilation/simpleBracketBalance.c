#include <stdio.h>
#include <string.h>

void balance(char*, char, char);

int main(void)
{
    char open, close;
    char stringCheck[200];
    printf("Введите через пробел виды открывающей и закрывающей скобки, на баланс которых мы будем проверять строку\n");
    scanf(" %c %c", &open, &close);
    getchar(); // очищаем поток от \n

    printf("Введите проверяемую строку:\n");
    fgets(stringCheck, 200, stdin);
    stringCheck[strcspn(stringCheck, "\n")] = '\0'; // удаляем последний элемент строки, если \n

    balance(stringCheck, open, close);

    return 0;
}

void balance(char* stringCheck, char open, char close)
{
    int countOpen = 0;
    int countClose = 0;
    for (size_t i = 0; i < strlen(stringCheck); i++) {
        if (stringCheck[i] == open)
            countOpen += 1;
        else if (stringCheck[i] == close)
            countClose += 1;
        if (countClose > countOpen) {
            printf("Во введенной строке НЕ соблюдается баланс скобок\n");
        }
    }
    if (countOpen == countClose)
        printf("Во введенной строке соблюдается баланс скобок\n");
    else
        printf("Во введенной строке НЕ соблюдается баланс скобок\n");
}
