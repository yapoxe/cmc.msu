/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>

enum { MAX = 4 };

int n = 0;

void f(int sign)
{
    if(n < MAX) {
        printf("%d\n", n++);
        fflush(stdout);
    } else {
        _exit(0);
    }
    signal(SIGINT, f);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, f);
    pid_t pid = getpid();
    printf("%d\n", pid);
    fflush(stdout);
    while(1) {
        pause();
    }
    return 0;
}