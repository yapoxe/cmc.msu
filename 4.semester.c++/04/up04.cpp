/*
Напишите шаблонную функцию myreverse, которая получает на вход два итератора произвольного доступа (begin и end) 
и переворачивает соответствующий контейнер, то есть первый элемент становится последним и наоборот.
Стандартными алгоритмами пользоваться запрещено.
Автор: Владимир (vk.com/yapoxe) 
*/
template <class A>

void func(A &x, A &y) {
    A tmp = x;
    x = y;
    y = tmp;
}

template <class B>

void myreverse(B begin, B end) {
    if ((begin == end) || (begin == --end)) {
        return;
    } else {
        while (begin < end) {
            func(*begin, *end);
            --end;
            ++begin;
        }
    }
}