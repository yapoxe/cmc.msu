/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

enum { PREFIX = 50 };

int
main(int argc, char **argv)
{
    char buf[PATH_MAX + PREFIX], p[3];
    unsigned int start, finish, fsum = 0, ssum = 0;
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        sscanf(buf, "%x-%x %c%c%c", &start, &finish, &p[0], &p[1], &p[2]);
        if(p[1] == 'w') {
            fsum += finish - start;
        }
        if(p[2] == 'x') {
            ssum += finish - start;
        }
    }
    printf("%u\n", fsum);
    printf("%u\n", ssum);
    return 0;
}