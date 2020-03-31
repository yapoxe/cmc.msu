// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
int main(void){
	long n,a,b;
	scanf("%li", &n);
	scanf("%li", &a);
	if(n==1){
		printf("%li", a);
		return 0;
	}
	for(long i=2; i<=n; i++){
		scanf("%li", &b);
		a=a^b;
	}
	printf("%li",a);
    return 0; 
}