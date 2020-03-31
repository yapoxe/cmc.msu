/*
Напишите функцию:
void normalize_path(char *buf);
Функция принимает на вход строку абсолютного пути. 
Строка всегда начинается с символа '/', в строке не встречаются несколько символов '/' подряд.
Если входная строка не равна "/" и оканчивается на '/', то этот символ с конца должен быть удален.
В строке-пути должны быть удалены все вхождения каталогов . 
и .. исходя из того, что каталог . — это переход на текущий каталог, а каталог .. — это переход на родительский каталог.
Функция модифицирует область памяти, в которой находится входная строка.
Запрещается использовать стандартные функции.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>

void normalize_path(char *buf)
{
    int i = 0;
    int j = 0;
    char *str = buf;
    while(buf[i] != 0) {
        if(buf[i] == '/' && buf[i+1] == '.' && buf[i+2] == '.'
                && (buf[i+3] == '\n' ||  buf[i+3] == '/' || buf[i+3] == 0)) {
            // If we find "/abcd/../" in BUF
            //                  ^ - element j
            j ? j-- : j;
            // "/abcd/../"
            //      ^ - element j
            while(str[j] != '/') {
                j--;
            }
            // "/abcd/../"
            //  ^ - element j
            // We skip part "abcd/.." and add char "/" to string
            str[j] = buf[i+3];
            i+=3;
            // "/abcd/../"
            //          ^ - element i
        } else if(buf[i] == '/' && buf[i+1] == '.' && (buf[i+2] == '\n' ||  buf[i+2] == '/' || buf[i+2] == 0)) {
            // If we find "/a/./" in BUF
            // Same as a previous step, but we skip "/." and add char "/" to string
            str[j] = buf[i+2];
            i+=2;
        } else {
            // If we dont find "/.." or "/." add char "/" or "%catalog_name" to string
            str[j] = buf[i];
            i++;
            j++;
        }
    }
    if(j > 1 && str[j-1] == '/') {
        // Delete last "/"
        // Example: "/a/" -> "/a"
        j--;
    }
    if(!j) {
        // If input empty
        str[0] = '/';
        j++;
    }
    str[j] = '\0';
}