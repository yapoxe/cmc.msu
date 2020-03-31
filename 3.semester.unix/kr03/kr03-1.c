/*
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[8], b = 0;
    int i = 0, j = 0;
    while(1) {
        for(i = 0; i < 8; i++) {
            if(scanf("%x", &a[i]) == EOF){
                return 0;
            }
        }
        for(i = 0; i < 8; i++) {
            b = 0;
            for(j = 0; j < 8; j++) {
                b = b | (((a[7 - j] >> i) & 1) << j);
            }
            printf("%x ", b);
        }
    }
    return 0;
}