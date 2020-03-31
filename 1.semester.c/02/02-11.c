// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>

int main(void){
	int a[8][8]={{0}}, i=0, j=0, n=0, m=0, c=64;
	char s[128];
	for(int l=0; l<128; l++){
		scanf("%c", &s[l]);
		if(s[l]=='\n'){
			break;
		}
		if(l%2==1){
			i=s[l-1]-'a';
			j=s[l]-'1';
			for(n=i-1; n<i+2; n++){
				if(n<0 || n>7){
					continue;
				}
				for(m=j-1; m<j+2; m++){
					if(m<0 || m>7 || a[n][m]==1){
						continue;
					}
					a[n][m]=1;
					c-=1;
				}
			}
		}
	}
	printf("%d", c);
    return 0; 
}