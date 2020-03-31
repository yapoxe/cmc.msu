/*
На стандартном потоке ввода задается последовательность 32-битных беззнаковых целых чисел. 
Последовательность заканчивается с концом файла.
Для каждого введенного числа на отдельной строке напечатайте 1, 
если это число может быть точно представлено в виде значения типа `float`, и 0 в противном случае.
В решении не используйте операции с вещественными числами.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>

enum { M_SIZE = 24 };

int
inttofloat(unsigned int a)
{
    char st = 0;
    char end = 0;
    char i = 0;
    char fl = 1;
    while(a) {
        if(a&1) {
            if(fl) {
                fl = 0;
                st = i;
            }
            end = i;
        }
        a >>= 1;
        ++i;
    }
    return end - st < M_SIZE;
}

int
main()
{
    unsigned int x = 0;
    while(scanf("%u", &x) != EOF) {
        printf("%i\n", inttofloat(x));
    }
    return 0;
}