// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <math.h>

int isprime(int k){
    if(k<2){
        return 0;
    }
    for(int i=2; i<=sqrt(k); i++){
        if(k%i==0){
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for(;;n++){
        if(isprime(n)){
            printf("%d", n);
            break;
        }
    }
    return 0;
}
