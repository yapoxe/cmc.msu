// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>

int main(void){ 
	int n, i, a1, a2, l=1, lm=1;
    scanf("%d", &n);
    scanf("%d", &a1);
    for(i=2; i<=n; i++){
    	a2=a1;
    	scanf("%d", &a1);
    	if(a1>a2){
    		l++;
    		if(l>lm){
    			lm=l;
    		}
    	}
    	else{
    		l=1;
    	}
    }
    printf("%d", lm);
    return 0; 
}