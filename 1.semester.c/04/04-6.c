// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <string.h>

int main(void){
	int n=0;
	scanf("%d\n", &n);
	char str[2000000]="";
	gets(str);
	int l=strlen(str), k=n-l, c=0, d=0;
	for (int i=0; i<l; ++i)
	{
		if(str[i]==' ' && str[i+1]!=' '){
			c++;
		}
	}
	if(n<=l){
		printf("%s", str);
		return 0;
	}
	d=k/c;
	c=k%c;
	for(int i=0; i<l; i++){
		if(str[i]==' ' && str[i+1]!=' '){
			printf("%c", str[i]);
			for(int j=0; j<d; j++){
				printf(" ");
			}
			if(c>0){
				printf(" ");
				c--;
			}
			continue;
		}
		printf("%c", str[i]);
	}
    return 0;
}
