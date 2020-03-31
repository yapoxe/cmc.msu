/*
Напишите шаблонную функцию selection_sort, которая была бы полностью совместима по использованию 
со стандартными шаблонными функциями сортировки, то есть везде, где используются sort или stable_sort, могла бы использоваться ваша функция сортировки.
Функция должна реализовывать алгоритм сортировки выбором.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <functional>
#include <algorithm>

template<typename A, typename T>

void selection_sort(A begin, A end, T comparator) {
    for (; begin != end;) {
        auto x = std::min_element(begin, end, comparator);
        std::iter_swap(x, begin);
        ++begin;
    }
}

template<typename A>

void selection_sort(A begin, A end) {
    typedef typename std::iterator_traits<A>::value_type value_type;
    selection_sort(begin, end, std::less<value_type>());
}