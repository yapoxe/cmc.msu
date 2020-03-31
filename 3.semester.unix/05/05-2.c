/*
В аргументах командной строки задается путь к каталогу.
На стандартный поток вывода напечатайте суммарный размер всех файлов в заданном каталоге (без подкаталогов), 
удовлетворяющих следующему условию:
Файл регулярный.
Его владельцем является текущий пользователь.
Его имя начинается с заглавной латинской буквы.
Для получения идентификатора пользователя процесса используйте системный вызов getuid.
Символические ссылки прослеживайте до соответствующих файлов (используйте соответствующий системный вызов семейства *stat).
Не используйте системные вызовы, меняющие текущий каталог процесса.
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

int
main(int argc, char **argv)
{
    long long size = 0;
    char buf[PATH_MAX];
    DIR *d = opendir(argv[1]);
    struct stat st;
    struct dirent *dd;
    int uid = getuid();
    while((dd = readdir(d)) != NULL) {
        snprintf(buf, sizeof(buf), "%s/%s", argv[1], dd->d_name);
        if(stat(buf, &st) < 0){
            continue;
        }
        if(S_ISREG(st.st_mode) && isupper(dd->d_name[0]) && (st.st_uid == uid)) {
            size += st.st_size;
        }
    }
    printf("%lld\n", size);
    return 0;
}