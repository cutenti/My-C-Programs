#include <stdio.h>

int main(void)
{
    printf("Введите размер массива: ");
    int len;
    scanf("%d", &len);

    printf("Введите элементы массива через пробел:\n");
    int array[len];
    int k = 0;
    for (int i = 0; i < len; i++) {
        scanf("%d", &array[i]);
        if (array[i] == 0) {
            k += 1;
        }
    }
    printf("Количество нулей в массиве = %d\n", k);
    return 0;
}
