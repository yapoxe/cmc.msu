// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>

int main(void){ 
	unsigned long i, n, k, k1=1, ma=0;
    scanf("%lu %lu", &n, &k);
    for(i=1; i<=k; i++){
        k1=k1<<1;
    }
    k1=k1-1;
    for(;;){
        if((n&k1)>ma){
            ma=n&k1;
        }
        n=n>>1;
        if(n==0){
            break;
        }
    }
    printf("%lu", ma);
    return 0; 
}