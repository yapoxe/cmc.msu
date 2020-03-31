// Автор:
// Владимир: https://vk.com/yapoxe
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int i=0, t=0, n=0;

int isprime(int a){
	for(i=2; i<sqrt(a); i++){
		if((a%i)==0){
			return 0;
		}
	}
	return 1;
}

int add(int k, int m){
	if(n==m+1){
		printf("%d ", k);
		return 0;
	}
	t=k*10+1;
	if(isprime(t)){
		add(t, m+1);
	}
	t=k*10+3;
	if(isprime(t)){
		add(t, m+1);
	}
	t=k*10+7;
	if(isprime(t)){
		add(t, m+1);
	}
	t=k*10+9;
	if(isprime(t)){
		add(t, m+1);
	}
	return 0;
}

int main(void){
	scanf("%d", &n);
    add(2, 0);
    add(3, 0);
    add(5, 0);
    add(7, 0);
    return 0;
}