/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int func(const char *str)
{
    int status;
    pid_t pid;
    if(!(pid = fork())) {
        execlp(str, str, NULL);
        _exit(1);
    } else if (pid > 0) {
        wait(&status);
        return WIFEXITED(status) && !WEXITSTATUS(status);
    } else {
        return 0;
    }
}

int
main(int argc, char **argv)
{
    return !((func(argv[1]) || func(argv[2])) && func(argv[3]));

}