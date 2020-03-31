// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>
#include <math.h>

float dl(float x, float y, float xp, float yp){
    return sqrt((xp-x)*(xp-x)+(yp-y)*(yp-y));
}

int main(void){
    float a, b, c, x, y, x2, y2, x3, y3, la=0, lb=0, lc=0;
    scanf("%f %f", &x, &y);
    scanf("%f %f", &x2, &y2);
    scanf("%f %f", &x3, &y3);
    a=dl(x, y, x2, y2);
    b=dl(x2, y2, x3, y3);
    c=dl(x3, y3, x, y);
    la=a/c;
    lb=a/b;
    lc=c/b;
    printf("%.5f %.5f\n", (x+lc*x2)/(1+lc), (y+lc*y2)/(1+lc));
    printf("%.5f %.5f\n", (x2+la*x3)/(1+la), (y2+la*y3)/(1+la));
    printf("%.5f %.5f", (x+lb*x3)/(1+lb), (y+lb*y3)/(1+lb));
    return 0;
}
