#include <stdio.h>
#include <stdlib.h>

int division(int, int);
int main(void)
{
    int a, b;
    printf("Введите a\t");
    scanf("%d", &a);
    printf("Введите b\t");
    scanf("%d", &b);
    int res = division(a, b);
    printf("%d / %d = %d\n%d = %d * %d + %d\n", a, b, res, a, b, res, a - b * res);
    return 0;
}

int division(int a, int b)
{
    int k = 0;
    if ((a > 0) && (b > 0)) {
        while (a >= b) {
            a -= b;
            k += 1;
        }
    } else if ((a > 0) && (b < 0)) {
        while (a >= abs(b)) {
            a += b;
            k -= 1;
        }
    } else if ((a < 0) && (b > 0)) {
        while (a < 0) {
            a += b;
            k -= 1;
        }
    } else if ((a < 0) && (b < 0)) {
        while (a < 0) {
            a -= b;
            k += 1;
        }
    }
    return k;
}
