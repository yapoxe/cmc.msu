// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *file=fopen("input.txt","r");
	int n=0, m=0, d=0, k=0;
	fscanf(file, "%d %d", &n, &m);
	int *a=(int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++) {
		a[i]=i+1;
	}
	for(int i=0; i<m; i++){
		fscanf(file, "%d", &d);
	}
	for(int i=0; i<n; i++){
		if(a[i]==d){
			k=i;
			break;
		}
	}
	fclose(file);
	file=fopen("output.txt","w");
	for(int j=k; j<n; j++){
		fprintf(file, "%d ", a[j]);
	}
	for(int j=0; j<k; j++){
		fprintf(file, "%d ", a[j]);
	}
	fclose(file);
	free(a);
	return 0;
}