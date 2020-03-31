/*
Напишите функцию process, которая принимает три параметра:
неизменяемый вектор целых чисел;
список целых чисел;
целый положительный параметр: шаг по вектору.
Функция проходит элементы вектора целых чисел с заданным шагом и копирует их в последовательные элементы списка (список проходится с шагом 1). 
Элементы вектора копируются "поверх" существующих элементов списка, если соответствующие элементы существуют.
Размер списка не должен измениться.
Затем все элементы списка выводятся на стандартный поток вывода в обратном порядке.
Для доступа к элементам массива и списка использовать только итераторы.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

void process(const std::vector<int> &v, std::list<int> &list, int step) {
    std::list<int>::iterator currentposl = list.begin();
    std::vector<int>::const_iterator currentposv = v.begin();
    for (; currentposv < v.end() && currentposl != list.end(); ++currentposl) {
        *currentposl = *currentposv;
        if(distance(currentposv, v.end()) <= step) break;
        currentposv += step;
    }
    std::list<int>::reverse_iterator currentpos = list.rbegin();
    for(;currentpos != list.rend(); currentpos++) {
        std::cout << *currentpos << '\n';
    }
}