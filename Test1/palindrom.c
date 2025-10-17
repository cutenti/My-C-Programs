#include <stdio.h>

int power(int number, int needPower)
{
    int needNumber = number;
    for (int i = 1; i < needPower; i++) {
        needNumber = needNumber * number;
    }
    return needNumber;
}

int lenMassBinNum(int number)
{
    int result;
    for (int i = 0; i < number; i++) {
        if (power(2, i) <= number) {
            result = i + 1;
        } else {
            break;
        }
    }
    return result;
}

int main(void)
{
    int number = 5;
    int lenMass = lenMassBinNum(number);
    int massiveBinNum[lenMass];
    //printf("%d\n\n", lenMass);
    int remainder;
    for (int i = 0; i < lenMass; i++) {
        remainder = number % 2;
        number = number / 2;
        massiveBinNum[i] = remainder;
    } //перевели число в двоичную запись :)
    /*for (size_t i = 0; i < sizeof(massiveBinNum) / sizeof(massiveBinNum[0]); i++) {
        printf("%d\n", massiveBinNum[i]);
    }*/
    int flag = 1;
    
    for (int i=0; i<i/2; i++)
    {
	
        if (massiveBinNum[i] != massiveBinNum[lenMass - i - 1]){
	    flag = 0;
	}
	flag = 1;
    }
    printf("%d\n", flag);
    return 0;
}
