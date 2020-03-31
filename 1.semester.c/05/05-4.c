// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	long int c, i=0, j=0;
	int a=0;
	long int *arr=malloc(2000000*sizeof(long int));
	scanf("%li", &c);
	while(c!=0){
		arr[i]=c;
		i++;
		scanf("%li", &c);
	}
	long int k=arr[i-1];
	for(j=0; j<i; j++){
		if(arr[j]<k){
			++a;
		}
	}
	printf("%d", a);
	free(arr);
    return 0;
}