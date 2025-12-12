Реализация стека в Stack.c 
и командой
$ gcc Stack.c -c
переведена в объектный файл Stack.o;

Объявления и описания всех функций лежат в заголовочном файле Stack.h;

Реализация проверки баланса скобок не вынесена в отдельный модуль;
Она в advancedBracketBalance.c

Чтобы собрать нужно ввести:
$ gcc -Wall -Wextra advancedBracketBalance.c Stack.o -o balance

Чтобы запустить:
$ ./balance