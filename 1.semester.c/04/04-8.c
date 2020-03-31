// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <string.h>

int main(void){
	char str[2000000]="";
	scanf("%s", str);
	int l=strlen(str), ch[1000]={0}, p=0, ich=0;
	if(l<3){
		printf("0");
		return 0;
	}
	for(int i=0; i<l; i++){
		for(int j=i+1; j<l; j++){
            for(int k=j+1; k<l; k++){
                p=((int)(str[i])-'0')*100+(((int)(str[j])-'0')*10+(int)(str[k])-'0');
                if(p<100){
                	continue;
                }
                for(int t=0; t<1000; t++){
                    if(ch[t]==p){
                        break;
                    }
                    if(ch[t]==0){
                    	ch[t]=p;
                    	ich=t;
                    	break;
                    }
                }
            }
		}
	}
	printf("%d", ich+1);
    return 0;
}
