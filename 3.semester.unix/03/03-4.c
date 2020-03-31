/*
На стандартном потоке ввода задается последовательность целых чисел (int). 
Целые числа записываются в десятичной форме со знаком + или - перед числом и разделяются одним 
или несколькими пробельными символами. 
Знак при положительном числе может опускаться.
На стандартный вывод напечатайте сумму этих чисел.
Для чтения со стандартного ввода используйте системный вызов read с размером буфера для чтения 16 байт!
Не накапливайте в памяти считываемые символы.
Не забывайте выводить символ перехода на новую строку в конце вывода!
Глобальные (и static) переменные запрещены.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

enum { SIZE = 16 };

int
main(void)
{
    ssize_t pt = 0;
    long long num = 0;
    long long sum = 0;
    int c = 0;
    int sf = 1;
    int end = 0;
    int index = 0;
    char buf[SIZE] = { 0 };
    while (1) {
        if (pt == index) {
            index = 0;
            pt = read(0, buf, sizeof(buf));
            if(!pt) {
                break;
            }
        }
        c = (unsigned char) buf[index++];
        if ((c >= '0') && (c <= '9')) {
            num = num * 10 + (c - '0');
            end = 1;
        }
        if (c == '-') {
            sf = -1;
        } else {
            if ((c != '+') && !isdigit(c) && end) {
                end = 0;
                sum += sf * num;
                num = 0;
                sf = 1;
            }
        }
    }
    sum += sf * num;
    printf("%lld\n", sum);
    return 0;
}