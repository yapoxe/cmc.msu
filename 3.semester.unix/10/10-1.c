/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int
main(void)
{
    int fd[2];
    int i;
    time_t t;
    pipe(fd);
    struct tm *st;
    if(!fork()) {
        if(!fork()) {
            if(!fork()) {
                read(fd[0], &t, sizeof(t));
                st = localtime(&t);
                printf("S:%02d\n", st->tm_sec);
                close(fd[1]);
                close(fd[0]);
                return 0;
            } else {
                wait(NULL);
                read(fd[0], &t, sizeof(t));
                st = localtime(&t);
                printf("M:%02d\n", st->tm_min);
                close(fd[1]);
                close(fd[0]);
                return 0;
            }
        } else {
            wait(NULL);
            read(fd[0], &t, sizeof(t));
            st = localtime(&t);
            printf("H:%02d\n", st->tm_hour);
            close(fd[1]);
            close(fd[0]);
            return 0;
        }
    } else {
        t = time(NULL);
        for (i = 0; i < 3; i++) {
            write(fd[1], &t, sizeof(t));
        }
        wait(NULL);
        close(fd[1]);
        close(fd[0]);
    }
    return 0;
}