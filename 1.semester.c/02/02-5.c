// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>

int main(void){ 
	int n, k=0;
    scanf("%d", &n);
    float a[n][4];
    for(int i=0; i<n; i++){
        scanf("%f %f %f %f", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        for(int j=0; j<i; j++){
            if((a[j][0]-a[i][0])*(a[j][0]-a[i][0])+(a[j][1]-a[i][1])*(a[j][1]-a[i][1])
                +(a[j][2]-a[i][2])*(a[j][2]-a[i][2])<=(a[j][3]+a[i][3])*(a[j][3]+a[i][3])){
                k=1;
            }
        }
    }
    if(k==1){
        printf("YES");
    }
    else{
        printf("NO");        
    }
    return 0; 
}