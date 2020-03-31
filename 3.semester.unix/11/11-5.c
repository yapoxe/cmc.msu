/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <signal.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

enum { MAX_NUMS = 3 };

volatile int last = 0;
volatile int count = 0;

int isprime(int n)
{
    if(n < 2) {
        return 0;
    }
    int max = (int) sqrt(n);
    for(int i = 2; i < max; ++i) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void
s_handler(int sign)
{
    if(sign == SIGTERM) {
        _exit(0);
    }
}

void
f_handler(int sign)
{
    if(sign == SIGINT) {
        if(count < MAX_NUMS) {
            printf("%d\n", last);
            fflush(stdout);
            count++;
        } else {
            _exit(0);
        }
    }
}

int
main(void)
{
    signal(SIGINT, f_handler);
    signal(SIGTERM, s_handler);
    printf("%d\n", getpid());
    fflush(stdout);
    int low;
    int high;
    int i;
    count = 0;
    scanf("%d %d", &low, &high);
    for(i = low; i < high; ++i) {
        if(isprime(i)) {
            last = i;
        }
    }
    printf("-1\n");
    fflush(stdout);
    return 0;
}