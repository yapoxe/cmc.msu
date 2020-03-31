// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
unsigned long long s=1,s1=1;
unsigned long long up(unsigned long long n, unsigned long long k){
    if(k==0){
        s1=s;
        s=1;
        return s1;
    }
    if(k>0){
        s=s*n;
        return up(n,k-1);       
    }
    else{
        s=s*n;
        return up(n,k+1);           
    }
}
int main(void){ 
	unsigned long long n,g1=0,g2;
    scanf("%llu", &n);
    g2=n;
    if(n>1000000000){
        printf("–1");
        return 0;
    }
    int s=0,i;
    for(i=0;;i++){
        if((g1+g2)>2000000){
            printf("-1");
            break;
        }
        if(n==0){
            printf("%d", s);
            break;
        }
        if(n%3==0){
            n=n/3;
            continue;
        }
        else{
            if(n%3==1){
                s+=1;
                g1+=up(3,i);
            }
            else{
                if(n%3==2){
                    s+=1;
                    g2+=up(3,i);
                    n+=1;
                }                
            }
        }
        n=n/3;
    }
    return 0; 
}