/*
На стандартный поток ввода программе подается текстовый файл, который мог быть подготовлен как в Unix, так и в Windows. 
Первая строка текста этого файла содержит имя текстового файла для обработки. 
Последующие строки исходного текстового файла должны игнорироваться.
Если файл существует и может быть прочитан, подсчитайте число вхождений каждого из символов десятичных цифр. 
Не существующий или нечитаемый файл полагайте пустым. Если стандартный поток ввода пуст, полагайте и 
обрабатываемый файл пустым. Если длина имени файла для обработки больше 61 полагайте обрабатываемый файл пустым.
Результат выведите в виде таблички:
<символ десятичной цифры> <число вхождений в файл этой цифры>
Не используйте глобальные переменные.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

enum CONST { STR_SIZE = 62, MAS_SIZE = 10 };

int
main(int argc, const char * argv[])
{
    long long a[MAS_SIZE] = { 0 };
    int i = 0;
    int l = 0;
    int ch = 0;
    char str[STR_SIZE];
    while(l < STR_SIZE) {
        ch = fgetc(stdin);
        if((ch == '\n') || (ch == EOF) || (ch == '\r')) {
            break;
        }
        str[l] = ch;
        l++;
    }
    if(l == STR_SIZE) {
        l--;
    }
    str[l] = '\0';
    FILE *fd;
    fd = fopen(str, "r");
    if(fd != NULL) {
        while((ch = fgetc(fd)) != EOF) {
            if(isdigit(ch)) a[ch - '0']++;
        }
        fclose(fd);
    }
    for(i = 0; i < MAS_SIZE; i++) {
        printf("%d %lld\n", i, a[i]);
    }
    return 0;
}