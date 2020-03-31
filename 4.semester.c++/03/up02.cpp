/*
Написать функцию process, принимающую два параметра:
неизменяемый вектор целых чисел v;
список целых чисел lst.
Функция должна удалить из списка lst элементы с номерами, заданными в векторе v. Элементы списка нумеруются от 1. 
Номера элементов списка отражают позиции элементов на момент начала работы программы. 
Если номер повторяется в массиве более одного раза, все вхождения, кроме первого, игнорируются. 
Если число в массиве не является допустимым номером элемента в списке, оно игнорируется.
Для доступа к элементам массива и списка использовать только итераторы.
При необходимости допускается создавать локальную копию вектора. Используйте std::sort, std::unique.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

void process(const std::vector<int> &v, std::list<int> &lst)
{
    int count = 1;
    std::vector<int> u(v.begin(), v.end());
    sort(u.begin(), u.end());
    auto point = unique(u.begin(), u.end());
    u.erase(point, u.end());
    auto currentlst = lst.begin();
    auto endlst = lst.end();
    auto currentu = u.begin();
    auto endu = u.end();
    size_t LstSize = lst.size();
    while (currentu != endu) {
        if (*currentu > 0) {
            if (size_t(*currentu) > LstSize || currentlst == endlst ) {
                break;
            }
            if (count < *currentu) {
                ++currentlst;
            } else if (count == *currentu) {
                currentlst = lst.erase(currentlst);
                endlst = lst.end();
                ++currentu;
            }
            ++count;
        } else {
            ++currentu;
        }
    }
}