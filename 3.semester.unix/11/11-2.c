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

volatile int status = 0;

void func(int sign)
{
    status = (sign == SIGUSR2);
}

int main(int argc, char **argv)
{
    int a;
    signal(SIGUSR1, func);
    signal(SIGUSR2, func);
    printf("%d\n", getpid());
    fflush(stdout);
    while(scanf("%d", &a) != EOF) {
        if(status) {
            printf("%d\n", a * a);
        } else {
            printf("%d\n", -a);
        }
        fflush(stdout);
    }
    return 0;
}