/*
В аргументах командной строки передаются: путь к каталогу, максимально допустимый суммарный размер 
файла в каталоге (64-битное целое число) и суффикс имени файлов - непустая строка, не содержащая символ '/'.
Если суммарный размер регулярных файлов в данном каталоге превышает заданное ограничение, 
необходимо вывести на стандартный поток вывода имя регулярного файла самого большого размера из файлов, 
имя которых оканчивается на указанный суффикс, если такой файл существует. Если файлов самого большого 
размера несколько, выведите лексикографически минимальное имя.
Файлы, являющиеся символическими ссылками, не рассматривать при подсчете размера и нахождении максимального файла.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>

int compare(const char *str1, const char *str2)
{
    int i;
    int j;
    for(i = strlen(str1) - 1, j = strlen(str2) - 1; (i >= 0) && (j >= 0); i--, j--) {
        if(str1[i] != str2[j]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv)
{
    DIR *d = opendir(argv[1]);
    unsigned long long max_sum = strtoll(argv[2], NULL, 10);
    unsigned long long max_size = 0;
    unsigned long long sum = 0;
    char buf[PATH_MAX];
    char fname[PATH_MAX];
    struct dirent *dir;
    struct stat st;
    fname[0] = 0;
    while((dir = readdir(d))) {
        snprintf(buf, sizeof(buf), "%s/%s", argv[1], dir->d_name);
        if((lstat(buf, &st) != -1) && S_ISREG(st.st_mode)) {
            sum += st.st_size;
            if(compare(dir->d_name, argv[3])) {
                if((strcmp(dir->d_name, fname) < 0) && (st.st_size == max_size)) {
                    snprintf(fname, sizeof(fname), "%s", dir->d_name);
                }
                if(st.st_size > max_size) {
                    snprintf(fname, sizeof(fname), "%s", dir->d_name);
                    max_size = st.st_size;
                }
            }
        }
    }
    closedir(d);
    if(fname[0] && (sum > max_sum)) {
        printf("%s\n", fname);
    }
    return 0;
}