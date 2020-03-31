// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[4000000];

int main(void){
	gets(str);
	int l=strlen(str);
	for(int i=0; i<l; i++){
		str[l+i]=str[i];
	}
	int i=0, last=0;
	while(i<l){
		int t=i, j=i+1;
		last=i;
		while (j<(2*l) && str[t]<=str[j]){
			if(str[t]<str[j]){
				t=i;	
			}
			else{
				++t;
			}
			++j;
		}
		while(i<=t){
			i+=j-t;
		}
	}
	for(int i=last; i<(last+l); i++){
		printf("%c", str[i]);
	}
    return 0;
}