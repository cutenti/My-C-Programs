#include <stdio.h>

int main(void)
{
    int fullCount = 0;
    int oneSummCount[28] = { 0 }; // для красоты добавления сумм будем считать с нулевой тоже
    int summ;

    for (int z1 = 0; z1 <= 9; z1++) { // первая цифра
        for (int z2 = 0; z2 <= 9; z2++) { // вторая цифра
            for (int z3 = 0; z3 <= 9; z3++) { // третья цифра
                if ((z1 <= z2) && (z2 <= z3)) { // чтобы не было повторов (мы же сочетания считаем)
                    summ = z1 + z2 + z3; // сумма текущих 3 цифр
                    if ((z1 == z2) && (z2 == z3)) { // все 3 цифры равны - один исход (С(3,3) = 3! / 3!*0!)
                        oneSummCount[summ] += 1;
                    } else if ((z1 == z2) || (z2 == z3)) { // 2 цифры равны - 3 исхода (C(2,3) = 3! / 2!*1!)
                        oneSummCount[summ] += 3;
                    } else { // 3 цифры разные - 6 исходов (C(1,3)*C(1,2) = 3!*2! / 2!*1!)
                        oneSummCount[summ] += 6;
                    }
                }
            }
        }
    }

    for (int summ = 1; summ <= 27; summ++) { // а теперь не берем нулевую сумму
        fullCount += oneSummCount[summ] * oneSummCount[summ];
    }

    printf("Количество счастливых билетиков = %d\n", fullCount);
    return 0;
}
