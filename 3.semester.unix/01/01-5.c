/*
На стандартном потоке ввода вводится последовательность пар из вещественного (double) и целого (int) числа. 
Максимальное число пар не превышает 16384.
На стандартный поток вывода напечатайте введенные пары, отсортированные в порядке неубывания первого числа в паре. 
Для равных значений первого числа должен сохраниться исходный (до сортировки) порядок пар.
Для печати вещественных чисел используйте форматное преобразование %.10g
Для сортировки используйте функцию сортировки стандартной библиотеки. Не пишите свою функцию сортировки!
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

enum { SIZE = 16384 };

typedef struct Mas
{
    double dvalue;
    int ivalue;
    int num;
} Mas;

int
compare(const void* a, const void* b)
{
    if (((Mas*)a)->dvalue < ((Mas*)b)->dvalue){
        return -1;
    } else if (((Mas*)a)->dvalue > ((Mas*)b)->dvalue){
        return 1;
    } else if (((Mas*)a)->dvalue == ((Mas*)b)->dvalue){
        return(((Mas*)a)->num - ((Mas*)b)->num);
    }
    return 0;
}

int
main(int argc, const char * argv[])
{
    int j = 0;
    int n = 0;
    Mas array[SIZE];
    while (scanf("%lf", &array[n].dvalue) != EOF){
        scanf("%d", &array[n].ivalue);
        array[n].num = n;
        n++;
    }
    qsort(array, n, sizeof(array[n]), compare);
    for (j = 0; j < n; j++){
        printf("%.10g %d\n", array[j].dvalue, array[j].ivalue);
    }
    return 0;
}