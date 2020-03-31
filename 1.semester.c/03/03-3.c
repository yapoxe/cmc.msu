// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <stdlib.h>
int f(int k){
    int c;
    scanf("%d", &c);
    if(c==0){
        printf("%d ", k);
        return 0;
    }
    f(c);
    printf("%d ", k);
    return 0;
}

int main(void){
    int n;
    scanf("%d", &n);
    if(n==0){
        return 0;
    }
    f(n);
    return 0;
}
