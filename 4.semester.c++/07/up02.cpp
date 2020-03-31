/*
Напишите функцию process, которая принимает по ссылке вектор элементов типа int, удаляет каждый элемент с четным индексом, 
а затем распечатывает в обратном порядке.
Для доступа к элементам вектора использовать только итераторы.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <vector>
#include <iostream>

void process(std::vector<int> &v) {
    bool fl = false;
    std::vector<int>::iterator cur;
    std::vector<int>::iterator pt = v.begin();
    for(cur = v.begin(); cur < v.end(); ++cur) {
        if(!fl) {
            fl = true;
        } else {
            fl = false;
            *pt = *cur;
            ++pt;
        }
    }
    v.erase(pt, v.end());
    cur = v.end();
    while(v.begin() < cur) {
        --cur;
        std::cout << *cur << std::endl;
    }
}