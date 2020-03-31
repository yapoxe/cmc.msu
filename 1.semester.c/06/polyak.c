// Автор:
// Владимир: https://vk.com/yapoxe
#include <stdio.h>

int main(void){
    int stack[1000], j=0, n=0, i=0;
    char s[1000];
    while(1){
        scanf("%c", &s[i]);
        if(s[i]=='\n'){
            ++i;
            n=i;
            break;
        }
        ++i;
    }
    for(i=n-2; i>=0; i--){
        switch (s[i]){
            case ' ':
                continue;
            case '+':
                stack[j-2] = stack[j-1] + stack[j-2];
                j--;
                break;
            case '-':
                stack[j-2] = stack[j-1] - stack[j-2];
                j--;
                break;
            case '*':
                stack[j-2] = stack[j-1] * stack[j-2];
                j--;
                break;
            case '/':
                stack[j-2] = stack[j-1] / stack[j-2];
                j--;
                break;
            default:
                stack[j] = s[i]-'0';
                j++;
        }
        if(i==0){
            printf("%d", stack[j - 1]);
            return 0;
        }
    }
    return 0;
}
