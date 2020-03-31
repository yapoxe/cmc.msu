/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/file.h>

int main(int agrc, char *argv[])
{
    int fd[2];
    if(!fork()) {
        fd[0] = open(argv[2], O_RDONLY);
        dup2(fd[0], 0);
        close(fd[0]);
        fd[1] = creat(argv[3], 0666);
        dup2(fd[1], 1);
        close(fd[1]);
        execl(argv[1], argv[1], NULL);
        _exit(1);
    } else {
        wait(NULL);
    }
    return 0;
}