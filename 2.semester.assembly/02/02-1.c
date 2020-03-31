//Автор:
//Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a=0, b=1, c=0;
    scanf("%d", &c);
    while(c){
        a=a^b;
        b=b^a;
        a=a^b;
        b+=a;
        --c;
    }
    printf("%d", a);
    a=0;
    return 0;
}
