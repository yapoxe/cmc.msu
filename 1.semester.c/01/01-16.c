// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
int main(void){
	float x1,x2,y1,y2,z1,z2,x,y;
	scanf("%f %f", &x1, &x2);
	scanf("%f %f", &y1, &y2);
	scanf("%f %f", &z1, &z2);
	x=(x1+y1+z1)/3;
	y=(x2+y2+z2)/3;
	printf("%.4lf %.4lf", x, y);
    return 0; 
}