// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <math.h> 

int main(void){
	int n;
	scanf("%d", &n);
	double s[n], a[n], v[n], at = 0.0;
	v[0] = 0;
	for(int i=0; i<n; i++){
		scanf("%lf", &s[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%lf", &a[i]);
		if(a[i]<=0.000001 && a[i]>=-0.000001){
			at+=s[i]/v[i];
			continue;
		}
		if(i+1<n){
			v[i+1]=sqrtf(v[i]*v[i]+2*a[i]*s[i]);
			at+=(-v[i]+v[i+1])/a[i];
		}
		else{
			at+=(-v[i]+sqrtf(v[i]*v[i]+2*a[i]*s[i]))/a[i];
		}
	}
	printf("%.4lf", at);
    return 0; 
}