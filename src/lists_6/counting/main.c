#include "cyclicList.h"
#include <stdio.h>

int correctN(int);
int correctM(int);

int main()
{
    int n, m;
    printf("Введите N:\n");
    scanf("%d", &n);
    printf("Введите M:\n");
    scanf("%d", &m);

    if (!correctM(m) || !correctN(n)) {
        printf("Вы ввели некорректные значения. Не может быть <1 человека и нельзя убивать каждого <=1-го\n");
        return 1;
    }

    if (n == 1) {
        printf("Убивать некого, 1 человек в кругу. Осталось только сделать харакири.\n");
        return 0;
    }

    printf("Чтобы выжить нужно встать на место %d\n", circle(n, m));
    return 0;
}

int correctN(int n)
{
    if (n < 1) {
        return 0;
    }
    return 1;
}

int correctM(int m)
{
    if (m <= 1) {
        return 0;
    }
    return 1;
}