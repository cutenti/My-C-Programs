#include <stdio.h>

int main(void)
{
    int fullCount = 0;
    int oneSummCount[28] = { 0 }; // для красоты добавления сумм будем считать с нулевой тоже
    int summ;

    for (int z1 = 0; z1 <= 9; z1++) { // первая цифра
        for (int z2 = 0; z2 <= 9; z2++) { // вторая цифра
            for (int z3 = 0; z3 <= 9; z3++) { // третья цифра
                    summ = z1 + z2 + z3; // сумма текущих 3 цифр
                    oneSummCount[summ]++;
            }
        }
    }

    for (int summ = 1; summ <= 27; summ++) { // а теперь не берем нулевую сумму
        fullCount += oneSummCount[summ] * oneSummCount[summ];
    }

    printf("Количество счастливых билетиков = %d\n", fullCount);
    return 0;
}
