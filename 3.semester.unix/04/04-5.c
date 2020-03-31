/*
Первая строка стандартного потока ввода содержит неотрицательное целое число - uid процесса.
Вторая строка содержит список целых неотрицательных чисел (не менее 1 и не более 32) - gid процесса.
Третья строка содержит запрашиваемую операцию (4 - read, 2 - write, 1 - execute), операции могут объединяться с помощью "или", 
например, 6 - read+write.
Следующие строки содержат описание файлов по одному описанию файла на строку. 
Описание файла содержит его uid, gid, права доступа - все целые неотрицательные числа, затем имя файла. 
Все пробельные символы между правами доступа и началом имени файла и перед концом строки не 
являются частью имени (то есть должны игнорироваться). 
Права задаются в восьмеричном виде.
На стандартный поток вывода напечатаейте имена файлов, к которым процесс с указанными в начале uid и gid может 
обращаться с указанной операцией. Каждое имя должно быть напечатано на отдельной строке.
Длины строк на стандартном потоке ввода не превышают 1020 символов.
Методические указания. Для последовательного чтения чисел из строки символов полезен спецификатор %n 
форматного ввода функции sscanf, либо второй параметр функции strtol. 
Не нужно вручную разбивать строку на числа.
Продумайте разбиение программы на функции. В частности, выделите проверку принадлежности группы списку групп в 
отдельную функцию.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum
{
    LEN = 1020,
    N = 32
};

int
check (int uid, int *gid, int n, int op, int uidf, int gidf, int right)
{
    int i;
    if (uid == uidf) {
        if ((op << 6) & right) {
            return 1;
        }
    }

    for (i = 0; i < n; i++) {
        if (gid[i] == gidf) {
            if ((op << 3) & right) {
                return 1;
            }
        }
    }

    if (op & right) {
        return 1;
    }

    return 0;
}

int
main(void)
{

    int uid, gid[N], op, i = 0, n, count = 0, len, cnt;
    int uidf, gidf, right;
    char buf[LEN];

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &uid);
    fgets(buf, sizeof(buf), stdin);
    len = strlen(buf) - 1;
    while (len) {
        sscanf(buf + count, "%d%n", &gid[i], &cnt);
        count += cnt;
        len -= cnt;
        i++;
    }
    n = i;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &op);

    while (fgets(buf, sizeof(buf), stdin)) {

        if (buf[0] == '\n') {
            continue;
        }
        sscanf(buf, "%d%d%o%n", &uidf, &gidf, &right, &count);

        count++;
        while (isspace(buf[count])) {
            count++;
        }

        if (check(uid, gid, n, op, uidf, gidf, right)) {
            printf ("%s", buf + count);
        }

    }

    return 0;
}
