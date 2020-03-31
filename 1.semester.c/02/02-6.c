// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>

int main(void){
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		b[i]=a[a[i]-1];
	}
	for(int i=0; i<n; i++){
		printf("%d ", b[a[i]-1]);
	}
    return 0; 
}