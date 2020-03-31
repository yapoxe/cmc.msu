// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
int s=0;
int nod(int n, int k){
	while(n!=k){
		if(n>k){
			n-=k;
		}
		else{
			k-=n;
		}
	}
	return n;
}
int nok(int n, int k){
	int m=n*k;
	while(n!=k){
		if(n>k){
			n-=k;
		}
		else{
			k-=n;
		}
	}
	return m/n;
}
int sum(int n, int k, int m, int p, int l){
	s=n*(l/m)+k*(l/p);
	return s;
}

int main(void){
	int n;
	scanf("%d", &n);
	int a, b, c, d, e=0;
	scanf("%d %d", &a, &b);
	for(int i=1; i<n; i++){
		scanf("%d %d", &c, &d);
		e=nok(b, d);
		a=sum(a, c, b, d, e);
		b=e;
	}
	b=1;
	if(s%e!=0){
		b=nod(s%e, e);
	}
	printf("%d %d %d", s/e, s%e/b, (s%e==0 ? 1 : e/b));
    return 0;
}