// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
enum{
    BUF_SIZE = 10000
};

int main(void){ 
	int a[BUF_SIZE], n, i=0;
    scanf("%i", &n);
    while(n!=0){
        a[i]=n;
        i++;
        scanf("%i", &n);
    }
    for(int j=0; j<i; j++){
        printf("%i ", a[i-j-1]);
    }
    return 0; 
}