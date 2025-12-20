#include <stdio.h>

int main(void)
{
    int x;
    printf("Введите х, для которого мы вычислим (x^4 + x^3 + x^2 + x + 1)\t");
    scanf("%d", &x);
    int x2 = x * x; // первое умножение
    long res = (x2 + 1) * (x2 + x) + 1; // второе умножение
    printf("результат равен %ld\n", res);
    return 0;
}
