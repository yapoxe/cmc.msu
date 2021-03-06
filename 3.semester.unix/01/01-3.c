/*
Напишите функцию
int mystrspccmp(const char *str1, const char *str2);
Функция должна лексикографически сравнивать строки, которые получались бы из строк str1 и str2 
полным удалением пробельных символов (whitespace characters). Функция возвращает значение 0, 
если две строки лексикографически равны, отрицательное значение, если первая строка лексикографически меньше второй, 
положительное значение, если первая строка лексикографически больше второй.
Гарантируется, что параметры str1 и str2 не равны NULL.
Запрещается использовать дополнительную память для преобразования строк. 
Запрещается использовать стандартные функции (кроме функций из ctype.h) и операции индексирования. 
Запрещается использовать операцию *(p + n). Используйте только указатели и указательную арифметику.
Например:
mystrspccmp("   de", "a") == 1 // допустимо любое положительное значение
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <ctype.h>

int
mystrspccmp(const char *str1, const char *str2)
{
    while(1) {
        while(isspace(*str1)) {
            str1++;
        }
        while(isspace(*str2)) {
            str2++;
        }
        if(*(unsigned char *) str1 != *(unsigned char *) str2) {
            return (unsigned char) *str1 - (unsigned char) *str2;
        }
        if(*str1 == 0) {
            return 0;
        }
        str1++;
        str2++;
    }
}