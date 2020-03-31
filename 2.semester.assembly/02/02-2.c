//Автор:
//Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <stdlib.h>

int main(void){
    unsigned long long a=0, b=0, k=0;
    scanf("%llu", &a);
    if(a==0){
        printf("2147483648");
        return 0;
    }
    while(a>4294967295){
        a-=4294967295;
        k=1;
    }
    b=a;
    --b;
    a=a^b;
    ++a;
    a=a>>1;
    if(k==1){
        k=k<<31;
        a=a|k;
    }
    printf("%llu", a);
    return 0;
}
