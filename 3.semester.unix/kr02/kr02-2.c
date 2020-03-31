/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

int
main(int argc, char **argv)
{
    int day, mon;
    struct tm data;
    scanf("%d %d %d", &data.tm_year, &data.tm_mon, &day);
    mon = data.tm_mon - 1;
    data.tm_min = 1;
    data.tm_hour = 1;
    data.tm_sec = 1;
    data.tm_year -= 1900;
    data.tm_mon -= 1;
    data.tm_mday = 1;
    mktime(&data);
    while(data.tm_mon == mon) {
        if(data.tm_wday == day) {
            printf("%d\n", data.tm_mday);
        }
        data.tm_mday++;
        mktime(&data);
    }
    return 0;
}