// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n=0, m=0, y=0, a=0, b=0, h=1;
	scanf("%d %d", &n, &m);
	scanf("%d", &y);
	int c=n*m-y;
	int **s=(int**)malloc(n*sizeof(int*));
	int i=0, j=0;
	for(i=0; i<n; i++) {
		s[i]=(int*)malloc(m*sizeof(int));
		for(j=0; j<m; j++){
			s[i][j]=0;
		}
	}
	for(i=0; i<y; i++){
		scanf("%d %d", &b, &a);
		s[a-1][b-1]=1;
	}
	while(c!=0){
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				if(s[i][j]==h){
					if(i-1>-1 && s[i-1][j]==0){
						s[i-1][j]=h+1;
						--c;
					}
					if(i+1<n && s[i+1][j]==0){
						s[i+1][j]=h+1;
						--c;
					}
					if(j-1>-1 && s[i][j-1]==0){
						s[i][j-1]=h+1;
						--c;
					}
					if(j+1<m && s[i][j+1]==0){
						s[i][j+1]=h+1;
						--c;
					}
				}
			}
		}
		++h;
	}
	printf("%d", h-1);
    return 0;
}
