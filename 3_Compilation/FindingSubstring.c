#include <stdio.h>
#include <string.h>

int main(void)
{
    char stringGiven[100];
    char substring[100];

    printf("Введите основную строку: ");
    fgets(stringGiven, sizeof(stringGiven), stdin);
    stringGiven[strcspn(stringGiven, "\n")] = '\0'; // последний символ переноса удаляем

    printf("Введите разыскиваемую подстроку: ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = '\0'; // последний символ переноса удаляем

    int count = 0; // количество вхождений
    int lenSubstring = strlen(substring);

    if (lenSubstring > 0) { // если подстрока существует хотя бы
        char* ptr = stringGiven; // указатель на первый элемент S
        while ((ptr = strstr(ptr, substring))) { // пока подстроки находятся
            count++;
            ptr += lenSubstring; // указываем на элемент, следующий после найденной подстроки
        }
    }

    printf("В строке \"%s\" содержится %d строк \"%s\" \n", stringGiven, count, substring);
    return 0;
}
