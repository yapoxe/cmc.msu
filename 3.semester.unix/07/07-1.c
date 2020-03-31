/*
Программе в аргументах командной строки задаются четыре целых 32-битных числа:
count (count >= 0, count < 100000) – число чисел для генерации;
low (low >= -32768);
high (0 <= high <= 32768, low < high);
seed (seed > 0).
На стандартный поток вывода напечатайте count псевдослучайных чисел в интервале [low, high), 
полученных с помощью функции rand() с начальным значением генератора, задаваемым seed.
Для получения случайных чисел из значения, возвращаемого rand() сначала получите 
вещественное число в полуинтервале [0;1), а затем из него получите требуемое целое число.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>

enum { SIZE = 10 };

int
main(int argc, char **argv)
{
    int num = 0;
    int count = strtol(argv[1], NULL, SIZE);
    int low = strtol(argv[2], NULL, SIZE);
    int high = strtol(argv[3], NULL, SIZE);
    int seed = strtol(argv[4], NULL, SIZE);
    srand(seed);
    for(int i = 1; i <= count; i++) {
        num = (int) (rand() / (RAND_MAX + 1.0) * (high - low)) + low;
        printf("%d\n", num);
    }
    return 0;
}