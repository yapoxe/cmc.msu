/*
В аргументах командной строки задается имя входного бинарного файла произвольного доступа. 
Бинарный файл рассматривается как массив структур:
struct Node
{
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};
Структура описывает вершину бинарного дерева поиска, где key – ключ поиска, а значения left_idx и right_idx – 
индексы в массиве соответственно левой и правой вершины. 
Корень дерева находится в элементе массива с индексом 0. 
Признаком отсутствия соответствующего поддерева в вершине является индекс, равный 0.
Числа в файле хранятся в естественном для x86 представлении (little-endian).
На стандартный поток вывода напечатайте ключи, размещенные в данном дереве, в порядке убывания.
Считывать содержимое всего файла в память целиком одним блоком запрещается. 
Для чтения содержимого файла необходимо пользоваться низкоуровневым вводом-выводом (open/read/etc). 
Корректная работа на big-endian архитектуре не требуется. Не используйте низкоуровневые манипуляции 
с памятью (union, приведение типов указателей). Не используйте библиотечные функции преобразования.
Для вывода ключей можно использовать высокоуровневые потоки (stdout).
Не забывайте выводить '\n' в конце вывода.
В программе должна быть реализована проверка корректности чтения из файла. 
Минимизируйте число системных вызовов, необходимых для чтения одной записи из файла.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct Node
{
    int key;
    int left_idx;
    int right_idx;
};

int
print_key(int fd, int index)
{
    long long n = 0;
    struct Node tree;
    lseek(fd, sizeof(struct Node) * index, SEEK_SET);
    while(n < sizeof(tree.key)) {
        n += read(fd, (char *) &tree.key + n, sizeof(tree.key) - n);
    }
    n = 0;
    while(n < sizeof(tree.left_idx)) {
        n += read(fd, (char *) &tree.left_idx + n, sizeof(tree.left_idx) - n);
    }
    n = 0;
    while(n < sizeof(tree.right_idx)) {
        n += read(fd, (char *) &tree.right_idx + n, sizeof(tree.right_idx) - n);
    }
    if(tree.right_idx) {
        print_key(fd, tree.right_idx);
    }
    printf("%d\n", tree.key);
    if(tree.left_idx) {
        print_key(fd, tree.left_idx);
    }
    return 0;
}

int
main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    print_key(fd, 0);
    close(fd);
    return 0;
}