/*
На стандартном потоке ввода задается последовательность целых чисел типа int, завершающаяся признаком конца файла. 
Для каждого введенного числа должен создаваться отдельный процесс, 
который выводит его же на стандартный поток вывода, но так, что в итоге последовательность чисел на стандартном потоке 
вывода окажется идущей в обратном порядке относительно чисел на стандартном потоке ввода. 
Дополнительный процесс может фикисировать признак конца ввода на стандартном потоке ввода.
Каждый процесс отвечает за чтение, хранение и вывод только одного числа из всей последовательности.
Например, если на стандартном потоке ввода задана последовательность 1 2 3, то в дополнение к родителю должно быть 
создано три процесса и на стандартный поток вывода должно быть выведено:
3
2
1
Если невозможно создать столько процессов, сколько чисел во входной последовательности, 
то вместо всей входной последовательности на стандартный поток вывода должно быть выведено число -1.
Стандартный поток ввода не является файлом произвольного доступа (является каналом).
Процесс-родитель должен завершаться самым последним из всех процессов. 
Этот процесс должен завершаться с кодом завершения 0 в любом случае.
Автор:
Владимир: https://vk.com/yapoxe
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int a, n = 0;
    pid_t pid;
    setbuf(stdout, NULL);
    while(scanf("%d", &a) != EOF) {
        n++;
        if((pid = fork()) > 0) {
            int status;
            wait(&status);
            if(!(WIFEXITED(status) && !WEXITSTATUS(status))) {
                if(n == 1) {
                    return 0;
                } else {
                    return 1;
                }
            }
            printf("%d\n", a);
            return 0;
        } else if (pid == -1) {
            printf("-1\n");
            return 1;
        }
    }
    return 0;
}