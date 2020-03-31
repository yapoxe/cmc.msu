/*
В аргументах командной строки передается имя бинарного файла произвольного доступа и 32-битное знаковое целое число A. 
Бинарный файл содержит структуры Data, описанные ниже.
struct Data
{
    int16_t x; // 2 байта,
    int64_t y; // 8 байт
};
Размер каждой структуры в файле - 10 байт, структуры в файле располагаются подряд.
Числа хранятся в представлении Little-Endian. 
Ваша программа должна корректно работать на платформах с любым порядком байт.
Преобразуйте файл следующим образом:
Измените порядок следования структур на противоположный, то есть первый элемент становится последним, 
второй - предпоследним и т. д.
Для каждой структуры модифицируйте значение поля y следующим образом: y += x * A. 
В случае арифметического переполнения выводите сообщение об ошибке и завершайте работу с кодом 3.
Хранить в памяти более двух структур не разрешается. Для ввода-вывода в файле использовать низкоуровневые средства.
Учтите, что sizeof(struct Data) может быть не равен 10, так как компилятор может выравнивать поля по определенным адресам. 
Но не используйте средства компилятора для управления выравниванием. Напишите функции для преобразования данных из 
формата хранения в файле во внутреннее представление в памяти и обратно.
Контролируйте корректность операций чтения и записи. В случае ошибки выведите сообщение об ошибке и завершите работу 
с кодом 2.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

enum
{
    SIZE = 10,
    SIZE_X = 2,
    SIZE_Y = 8
};

struct Data
{
    short x;
    long long y;
};

void
my_read(int fd, void *buf, int n)
{
    int nr;
    char *p = (char *)buf;
    while (n > 0) {
        nr = read(fd, p, n);
        p += nr;
        n -= nr;
    }
}

void
my_write(int fd, void *buf, int n)
{
    int nr;
    char *p = (char *)buf;
    while (n > 0) {
        nr = write(fd, p, n);
        p += nr;
        n -= nr;
    }
}

int
main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDWR);
    int n, i, a;
    short x1, x2;
    long long y1, y2;

    sscanf(argv[2], "%d", &a);
    n = lseek(fd, 0, SEEK_END);
    n /= SIZE;

    for (i = 0; i < n / 2; i++) {
        lseek(fd, i * SIZE, SEEK_SET);
        my_read(fd, &x1, SIZE_X);
        my_read(fd, &y1, SIZE_Y);
        y1 += x1 * a;
        lseek(fd, - (i + 1) * SIZE, SEEK_END);
        my_read(fd, &x2, SIZE_X);
        my_read(fd, &y2, SIZE_Y);
        y2 += x2 * a;
        lseek(fd, i * SIZE, SEEK_SET);
        my_write(fd, &x2, SIZE_X);
        my_write(fd, &y2, SIZE_Y);
        lseek(fd, - (i + 1) * SIZE, SEEK_END);
        my_write(fd, &x1, SIZE_X);
        my_write(fd, &y1, SIZE_Y);
    }

    if (n % 2) {
        lseek(fd, (n / 2) * SIZE, SEEK_SET);
        my_read(fd, &x1, SIZE_X);
        my_read(fd, &y1, SIZE_Y);
        y1 += x1 * a;
        lseek(fd, (n / 2) * SIZE, SEEK_SET);
        my_write(fd, &x1, SIZE_X);
        my_write(fd, &y1, SIZE_Y);
    }
    close(fd);
    return 0;
}