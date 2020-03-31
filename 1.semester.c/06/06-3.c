// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *file=fopen("input.txt","r");
	int *a=(int*)malloc(4000*sizeof(int)), k=1, c=0;
	for(int i=0; i<4000; i++) {
		a[i]=0;
	}
	while(fscanf(file, "%d", &a[k-1])!=EOF){
		k++;
	}
	fclose(file);
	file=fopen("output.txt","w");
	for(int i=0; i<k-1; i++){
		for(int j=0; j<k-1; j++){
			if(a[j]>a[i]){
				c=a[j];
				a[j]=a[i];
				a[i]=c;
			}
		}
	}
	for(int i=0; i<k-1; i++){
		fprintf(file, "%d ", a[i]);
	}
	fclose(file);
	free(a);
	return 0;
}