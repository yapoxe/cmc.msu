/*
Напишите функцию
int
parse_rwx_permissions(const char *str);
На вход функции подается строка — права доступа к файлу в формате rwx (9 знаков). Указатель может принимать значение NULL.
Функция должна вернуть соответствующее значение прав доступа, либо -1, если строка не является корректной записью прав 
доступа. Корректная запись состоит только из символов '-', 'r', 'w', 'x', расположенных в правильном порядке.
Указание: используйте строку-образец "rwxrwxrwx" для разбора входной строки. В функции не должны использоваться константы 3,
 8, 9, 10 (даже в виде enum или #define). Используйте битовые операции.
Поскольку строка-образец является константной, ее длину можно вычислить за константное время на этапе компиляции.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <string.h>
 
int
parse_rwx_permissions(const char *str)
{
    const char *example = "rwxrwxrwx";
    int result = 0, i, length;
    if (str == NULL){
        return EOF;
    }
    length = strlen(str);
    if (length != strlen(example)){
        return EOF;
    }
    for (i = 0; i < length; i++){
        if ((str[i] != example[i]) && (str[i] != '-')){
            return EOF;
        }
        result += ((str[i] - '-') && 1) << (length - 1 - i);
    }
    return result;
}