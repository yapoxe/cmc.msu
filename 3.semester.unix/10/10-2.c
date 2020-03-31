/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>

int
main(void)
{
    int fd[2];
    pipe(fd);
    int a, b;
    long long sum;
    if(!fork()) {
        if(!fork()) {
            sum = 0;
            close(fd[1]);
            while(read(fd[0], &b, sizeof(b)) > 0) {
                sum += b;
            }
            printf("%lld\n", sum);
            close(fd[0]);
            exit(0);
        } else {
            close(fd[1]);
            close(fd[0]);
            wait(NULL);
            exit(0);
        }
    } else {
        close(fd[0]);
        while (scanf("%d", &a) != EOF) {
            write(fd[1], &a, sizeof(a));
        }
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}