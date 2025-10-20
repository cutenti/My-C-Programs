#include <stdio.h>

int main(void)
{
    printf("Введите число от 0 до 27:\t");
    int givenSum;
    scanf("%d", &givenSum);
    int k = 0;
    for (int z1 = 0; z1 <= 9; z1++) {
        for (int z2 = 0; z2 <= 9; z2++) {
            for (int z3 = 0; z3 <= 9; z3++) {
                for (int z4 = 0; z4 <= 9; z4++) {
                    for (int z5 = 0; z5 <= 9; z5++) {
                        for (int z6 = 0; z6 <= 9; z6++) {
                            int sum123 = z1 + z2 + z3;
                            int sum456 = z4 + z5 + z6;
                            if ((sum123 == sum456) && (sum123 == givenSum)) {
                                k += 1;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Количество счастливых билетиков с заданной суммой трех цифр = %d\n", k);
    return 0;
}
