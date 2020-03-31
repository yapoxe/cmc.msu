// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <stdlib.h>
int med(int x, int y, int z){
    if(y<=z){
        if(x>=z){
            return z;
        }
        if(x<=y){
            return y;
        }
        else{
            return x;
        }
    }
    else{
        if(x>=y){
            return y;
        }
        if(x>=z){
            return x;
        }
        else{
            return z;
        }
    }
    return 0;
}

int main(void)
{
    int n, k=0;
    scanf("%d", &n);
    int a[n], b[n-2];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    while(n>1){
        if(k==0){
            for(int i=0; i<n-2; i++){
                b[i]=med(a[i], a[i+1], a[i+2]);
            }
            ++k;
            n=n-2;
            continue;
        }
        for(int i=0; i<n-2; i++){
            a[i]=med(b[i], b[i+1], b[i+2]);
        }
        --k;
        n=n-2;
    }
    if(k==1){
        printf("%d", b[0]);
        return 0;
    }
    printf("%d", a[0]);
    return 0;
}
