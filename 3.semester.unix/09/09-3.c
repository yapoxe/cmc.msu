/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int mysys(const char *str)
{
    int pid;
    int status;
    if(!(pid = fork())) {
        execlp("sh", "sh", "-c", str, NULL);
        _exit(1);
    } else if(pid == -1) {
        return -1;
    }
    waitpid(pid, &status, 0);
    if(WIFSIGNALED(status)) {
        return 128 + WTERMSIG(status);
    }
    if(WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }
    return 0;
}