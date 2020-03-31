/*
На стандартный поток ввода программы подается последовательность целых чисел типа unsigned short в текстовом виде. 
В файл, имя которого указано в аргументе командной строки, запишите эту последовательность чисел в бинарном виде. 
Числа должны записываться в формате Big Endian (старшая половина первой).
Выходной файл должен быть создан с правами только на чтение и запись только для владельца, если он не существовал.
Для записи выходного файла используйте POSIX API.
Для записи чисел используйте системный вызов write, в который передается буфер размера 2.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <unistd.h>

enum BIN { BUF_SIZE = 2 };

int
main(int argc, const char * argv[]) {
    unsigned short us;
    int fd;
    char buf[BUF_SIZE];
    fd = open(argv[1],  O_CREAT | O_TRUNC | O_WRONLY, 0600);
    while(scanf("%hu", &us) != EOF) {
        buf[1] = us;
        buf[0] = us >> 8;
        write(fd, buf, sizeof(buf));
    }
    return 0;
}