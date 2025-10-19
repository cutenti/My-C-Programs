#include <stdio.h>

// Алгоритм Реверса

void reverse(int*, int, int);

int main(void)
{
    int m;
    int n;
    printf("Введите длину первого отрезка:\n");
    scanf("%d", &m);
    printf("Введите длину второго отрезка:\n");
    scanf("%d", &n);

    int x[n + m];
    printf("Введите числа для первого отрезка:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &x[i]);
    }
    printf("Введите числа для второго отрезка:\n");
    for (int i = m; i < m + n; i++) {
        scanf("%d", &x[i]);
    }
    printf("До переворота: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d\t", x[i]);
    }
    printf("\n");
    reverse(x, 0, n + m - 1);
    reverse(x, 0, n - 1);
    reverse(x, n, n + m - 1);

    printf("После переворота: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d\t", x[i]);
    }
    printf("\n");
    return 0;
}

void reverse(int* x, int start, int end)
{
    int var;
    while (start < end) {
        var = x[start];
        x[start] = x[end];
        x[end] = var;
        start++;
        end--;
    }
}
