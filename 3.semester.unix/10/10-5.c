/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int i = 1;
    int fd[2][2];
    long int n = strtol(argv[1], NULL, 10) - 1;
    pipe(fd[1]);
    pipe(fd[0]);
    FILE *fl2_wr = fdopen(fd[0][1], "w");
    FILE *fl2_rd = fdopen(fd[1][0], "r");
    FILE *fl1_wr = fdopen(fd[1][1], "w");
    FILE *fl1_rd = fdopen(fd[0][0], "r");
    FILE *str = fdopen(STDOUT_FILENO, "w");
    if(i < n) {
        fprintf(fl2_wr, "%d ", i);
        fflush(fl2_wr);
        if(!fork()) {
            fclose(fl2_rd);
            fclose(fl2_wr);
            while((i < n) && (fscanf(fl1_rd, "%d", &i) != EOF)) {
                fprintf(str, "1 %d\n", i++);
                fflush(str);
                fprintf(fl1_wr, "%d ", i);
                fflush(fl1_wr);
            }
            _exit(0);
        }
        if(!fork()) {
            fclose(fl1_rd);
            fclose(fl1_wr);
            while((i < n) && (fscanf(fl2_rd, "%d", &i) != EOF)) {
                fprintf(str, "2 %d\n", i++);
                fflush(str);
                fprintf(fl2_wr, "%d ", i);
                fflush(fl2_wr);
            }
            _exit(0);
        }
    } else if (n == i) {
        fprintf(str, "1 1\n");
        fflush(str);
    }
    fclose(fl2_wr);
    fclose(fl2_rd);
    fclose(fl1_wr);
    fclose(fl1_rd);
    wait(NULL);
    wait(NULL);
    printf("Done\n");
    return 0;
}