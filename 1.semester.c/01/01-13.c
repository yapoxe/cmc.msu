// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
float a, s=0, b;
long long n, i, l=4;
int main(void){
	scanf("%f %lli", &a, &n);
	b=a;
	for(i=1; i<=n; i++){
		s+=b;
		b*=(-1)*(a*a)/((l-1)*(l-2));
		l+=2;
	}
	printf("%.6lf", s);
    return 0; 
}