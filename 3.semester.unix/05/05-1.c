/*
На стандартном потоке ввода записана последовательность целых знаковых 32-битных чисел.
Каждое число обозначает число дней от текущего момента времени.
Для каждого числа на стандартный поток вывода напечатайте календарную дату, которая будет ровно через 
это число суток после текущего момента времени.
Календарную дату выводите в формате YYYY-MM-DD, например,
2015-10-12
Если результирующая дата или промежуточные результаты вычислений (число секунд в заданом числе дней) 
будут непредставимы в типе time_t напечатайте строку OVERFLOW.
Для каждой входной даты ответ выводите на отдельной строке.
Для получения текущего момента времени используйте системный вызов time. Не используйте mktime.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <time.h>
#include <memory.h>

enum { SEC = 86400, YEAR = 1900 };

int main(void)
{
    time_t current = time(NULL);
    time_t out;
    int days, result;
    struct tm time;
    while (scanf("%d", &days) == 1) {
        memset(&time, 0, sizeof(time));
        time.tm_isdst = -1;
        if (__builtin_mul_overflow(SEC, days, &result)) {
            printf("OVERFLOW\n");
        } else if (__builtin_add_overflow(current, result, &out)) {
            printf("OVERFLOW\n");
        } else {
            localtime_r(&out, &time);
            printf("%04d-%02d-%02d\n", time.tm_year + YEAR, time.tm_mon + 1, time.tm_mday);
        }
    }
    return 0;
}