// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	long int c, i=0, j=0;
	long int *arr=malloc(2000000*sizeof(long int));
	scanf("%li", &c);
	while(c!=0){
		arr[i]=c;
		i++;
		scanf("%li", &c);
	}
	for(j=0; j<i+1; j=j+2){
		if(arr[j]==0){
			break;
		}
		printf("%li ", arr[j]);
	}
	for(j=1; j<i+1; j=j+2){
		if(arr[j]==0){
			break;
		}
		printf("%li ", arr[j]);
	}
	free(arr);
    return 0;
}