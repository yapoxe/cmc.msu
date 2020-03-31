// Автор:
// Владимир: https://vk.com/yapoxe

#include <stdio.h>

int main(void){ 
	int n,i,a,ma,mi;
    scanf("%d", &n);
    scanf("%d", &a);
    mi=a;
    ma=a;
    for(i=2; i<=n; i++){
    	scanf("%d", &a);
    	if(a>ma){
    		ma=a;
    	}
    	if(a<mi){
    		mi=a;
    	}
    }
    printf("%d", ma-mi);
    return 0; 
}