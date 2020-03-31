/*
В аргументах командной строки передается путь к каталогу. Этот каталог является корнем поддерева файловой системы.
Обойдите рекурсивно все подкаталоги и на стандартный поток вывода напечатайте команды 'cd', 
с помощью которых можно обойти все подкаталоги и вернуться в исходный каталог. 
Каждая команда cd может переходить на один каталог вверх/вниз по иерархии.
Никакого экранирования спецсимволов не требуется.
В одном каталоге подкаталоги должны просматриваться в лексикографическом порядке без учета регистра букв. 
Сравнение без учета регистра букв выполняется функцией strcasecmp. 
Каталог, который нельзя открыть на чтение с помощью opendir, должен быть пропущен, 
то есть в него не нужно входить и из него не нужно выходить.
Гарантируется, что в одном каталоге не присутствуют каталоги, отличающиеся только регистром букв.
Не используйте scandir, ftw и аналогичные функции. 
Не используйте chdir, fchdir. Можно использовать opendir, readdir, closedir и *stat.
Обрабатывать пути длиннее чем PATH_MAX-1 не требуется.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

int
comparef(const void *str1, const void *str2)
{
    return strcasecmp(*(char **) str1, *(char **) str2);
}

int
recursive_cycle(const char *dir)
{
    char buf[PATH_MAX];
    struct stat st;
    struct dirent *dd;
    DIR *dr;
    if(!(dr = opendir(dir))) {
        return 1;
    }
    int i = 0;
    int j = 0;
    int n = 64;
    char **str = malloc(n * sizeof(*str));
    while((dd = readdir(dr))) {
        if(strcmp(dd->d_name, ".") && strcmp(dd->d_name, "..")) {
            if(!strcmp(dir, "/")) {
                snprintf(buf, sizeof(buf), "%s%s", dir, dd->d_name);
            } else {
                snprintf(buf, sizeof(buf), "%s/%s", dir, dd->d_name);
            }
            if(lstat(buf, &st) != -1) {
                DIR *a;
                if(S_ISDIR(st.st_mode) && (a = opendir(buf))) {
                    if(i == n) {
                        str = realloc(str, (n *= 2) * sizeof(*str));
                    }
                    closedir(a);
                    str[i++] = strdup(dd->d_name);
                }
            }
        }
    }
    closedir(dr);
    qsort(str, i, sizeof(*str), comparef);
    for(j = 0; j < i; j++) {
        printf("cd %s\n", str[j]);
        if(!strcmp(dir, "/")) {
            snprintf(buf, sizeof(buf), "%s%s", dir, str[j]);
        } else {
            snprintf(buf, sizeof(buf), "%s/%s", dir, str[j]);
        }
        free(str[j]);
        recursive_cycle(buf);
        printf("cd ..\n");
    }
    free(str);
    return 1;
}

int
main(int argc, char **argv)
{
    recursive_cycle(argv[1]);
    return 0;
}