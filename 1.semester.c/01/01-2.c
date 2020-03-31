// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>

int main(void){ 
	int n,i,a,ma,k=1;
    scanf("%d", &n);
    scanf("%d", &a);
    ma=a;
    for(i=2; i<=n; i++){
    	scanf("%d", &a);
    	if(a>ma){
    		ma=a;
    		k=1;
    		continue;
    	}
    	if(a==ma){
    		k++;
    	}
    }
    printf("%d", k);
    return 0; 
}