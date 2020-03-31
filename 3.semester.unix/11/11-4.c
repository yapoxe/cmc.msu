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

int f_proc;
int s_proc;
int fl = 0;

void source_func(int sign)
{
    if(sign != SIGUSR1) {
        kill(f_proc, SIGUSR1);
    } else {
        kill(s_proc, SIGUSR2);
    }
}

void chld_func(int signum)
{
    fl += 1;
    return;
}

int main(int argc, char *argv[])
{
    int fd[2];
    pipe(fd);
    int a = 1;
    long int lim = strtol(argv[1], NULL, 10);
    FILE *f_out = fdopen(fd[1], "w");
    FILE *f_in = fdopen(fd[0], "r");
    FILE *out = fdopen(STDOUT_FILENO, "w");
    setbuf(f_out, NULL);
    fprintf(f_out, "%d ", a);
    setbuf(out, NULL);
    signal(SIGUSR1, chld_func);
    if((f_proc = fork()) == 0) {
        while(1) {
            while(!fl) {
                usleep(1);
            }
            fscanf(f_in, "%d", &a);
            if(lim > a) {
                fl = 0;
                fprintf(out, "1 %d\n", a++);
                fprintf(f_out, "%d ", a);
                kill(getppid(), SIGUSR1);
            } else {
                fprintf(f_out, "%d ", a);
                fclose(f_out);
                fclose(f_in);
                kill(getppid(), SIGUSR1);
                _exit(0);
            }
        }
    }
    signal(SIGUSR1, source_func);
    signal(SIGUSR2, chld_func);
    if((s_proc = fork()) == 0) {
        while(1) {
            while(!fl) {
                usleep(1);
            }
            fscanf(f_in, "%d", &a);
            if(a < lim) {
                fl = 0;
                fprintf(out, "2 %d\n", a);
                a += 1;
                fprintf(f_out, "%d ", a);
                kill(getppid(), SIGUSR2);
            } else {
                fprintf(f_out, "%d ", a);
                fclose(f_in);
                fclose(f_out);
                kill(getppid(), SIGUSR2);
                exit(0);
            }
        }
    }
    signal(SIGUSR2, source_func);
    fclose(f_in);
    fclose(f_out);
    kill(f_proc, SIGUSR1);
    wait(NULL);
    wait(NULL);
    printf("Done\n");
    return 0;
}