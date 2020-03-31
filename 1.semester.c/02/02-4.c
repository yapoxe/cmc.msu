// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>

int main(void){ 
	int n, k=0, s=0;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &k);
        if(k>a[i]){
            s+=k;
        }
        else{
            s+=a[i];
        }
    }
    printf("%d", s);
    return 0; 
}