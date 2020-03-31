// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <stdlib.h>

int kon(int x, int y, int z, int h){
	if((abs(z-x)==2) && (abs(h-y)==1)){
		return 1;
	}
	if((abs(z-x)==1) && (abs(h-y)==2)){
		return 1;
	}
	return 0;
}

int ferz(int x, int y, int z, int h){
	if(h==y || x==z || abs(x-z)==abs(y-h)){
		return 1;
	}
	return 0;
}

int main(void)
{
    int k=1, a=0, b=0, c=0, d=0, m=0, u=0;
    char s[128];
    for(int i=0;;i++){
        scanf("%c", &s[i]);
        if(i>=128 || s[i]=='X'){
            break;
        }
        if(s[i]>='A'){
            a=(int)(s[i])-'A';
            continue;
        }
        if(s[i]<'0'){
        	continue;
        }
        else{
            b=(int)(s[i])-'1';
            if(a==c && b==d){
            	m=1;
            }
            if(k==1){
            	--k;
                if(kon(a, b, c, d)){
                    if(m!=1 && m!=4){
                        m=2;
                    }
                    if(a==7 && b==7){
                    	u+=1;
                    }
                    c=a;
                    d=b;
                    continue;
                }
                else{
                    m=1;
                }
            }
            else{
            	++k;
                if(ferz(a, b, c, d)){
                    if(m!=1 && m!=4){
                        m=3;
                    }
                    if(a==7 && b==7){
                    	u+=1;
                    }
                    c=a;
                    d=b;
                    continue;
                }
                else{
                    m=1;
                }
            }
        }
    }
    if(a!=('H'-'A') || b!=('8'-'1') || u>1){
		printf("Cheaters");
		return 0;
    }
    switch(m){
        case 1: printf("Cheaters"); break;
        case 2: printf("Garik"); break;
        case 3: printf("Tolik"); break;
        case 4: printf("Cheaters"); break;
        default: printf("Cheaters"); break;
    }

    return 0;
}
