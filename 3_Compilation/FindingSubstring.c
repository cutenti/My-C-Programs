#include <stdio.h> //нужно заменить scanf на fgets, чтобы считывать пробелы
#include <string.h>

int main(void)
{
    char S[100];
    char S1[100];
    printf("Введите основную строку: ");
    fgets(S, 100, stdin);
    S[strcspn(S, "\n")] = '\0';
    printf("Введите разыскиваемую подстроку: ");
    fgets(S1, 100, stdin);
    S1[strcspn(S1, "\n")] = '\0';

    int lenS = strlen(S);
    int lenS1 = strlen(S1);
    int countSubstr = 0;
    int i = 0;
    int j = 0;
    int equalLet = 0;
    while (i < lenS) {
        if (S[i] == S1[j]) {
            equalLet += 1;
            if (equalLet == lenS1) {
                countSubstr += 1;
                j = 0;
                equalLet = 0;
            } else {
                j++;
            }
        } else {
            equalLet = 0;
            j = 0;
        }
        i++;
    }
    printf("В строке \"%s\" содержится %d строк \"%s\" \n", S, countSubstr, S1);
    return 0;
}
