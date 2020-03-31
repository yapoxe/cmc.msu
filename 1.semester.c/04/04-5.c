// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <string.h>

int main(void){ 
	int n;
	scanf("%d", &n);
	char str[80];
	scanf("%s", str);
	int l=strlen(str), k=n%l;
	if(k==0){
		printf("%s\n", str);
		return 0;
	}
	for(int i=k; i<l; i++){
		printf("%c", str[i]);
	}
	for(int i=0; i<k; i++){
		printf("%c", str[i]);
	}
    return 0; 
}