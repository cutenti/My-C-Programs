#include <stdio.h>
#include <stdlib.h>

int division(int, int);
int main(void)
{
    int A, B;
    printf("Введите A и B\t");
    scanf("%d %d", &A, &B);

    division(A, B);
    return 0;
}

int division(int A, int B)
{
    int quotient = 0;

    if (B == 0) {
        printf("\nДелить на 0 нельзя.\n");
        return 1;
    }

    int absA = abs(A);
    int absB = abs(B);

    while (absA >= absB) {
        absA -= absB;
        quotient += 1;
    }

    if (A * B < 0) {
        quotient *= -1;
    }

    printf("\nНеполное частное (%d / %d) = %d\n", A, B, quotient);
    return 0;
}
