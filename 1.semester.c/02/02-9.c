// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>

int main(void){ 
	int n, m, i, s=0, k=1, j;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	int b[m];
	for(i=0; i<m; i++){
		scanf("%d", &b[i]);
		for(j=0; j<n; j++){
			s+=a[j]*k;
			k*=b[i];
		}
		k=1;
		b[i]=s;
		s=0;
	}
	for(i=0; i<m; i++){
		printf("%d ", b[m-i-1]);
	}	
    return 0; 
}