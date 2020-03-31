/*
Напишите функцию
void copy_file(int in_fd, int out_fd);
Функция должна скопировать все данные из файлового дескриптора in_fd в файловый дескриптор out_fd.
Для буферизации ввода используйте локальный буфер размера 4096 байт.
Используйте POSIX API работы с файлами.
Помните, что read не обязан всегда считывать ровно то количество байт, которое было запрошено.
Помните, что write не обязан всегда записывать ровно то количество байт, которое было запрошено.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <unistd.h>
#include <sys/types.h>

void copy_file(int in_fd, int out_fd)
{
    char buff[4096];
    ssize_t n;
    ssize_t k;
    while((n = read(in_fd, buff, sizeof(buff))) > 0) {
        char *pt = buff;
        while(n) {
            if((k = write(out_fd, pt, n)) < 0) {
                break;
            }
            n -= k;
            pt += k;
        }
    }
}