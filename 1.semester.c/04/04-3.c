// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <string.h>

int main(void){
	char str[10000];
	scanf("%s", str);
	int l=strlen(str), k=0;
	for(int t=1; t<=l; t++){
		for(int i=0; i<l; i++){
			if(i-t<0){
				continue;
			}
			if(str[i]!=str[i-t]){
				k=1;
				break;
			}
		}
		if(k==1){
			k=0;
			continue;
		}
		printf("%d ", t);
		k=0;
	}
    return 0;
}