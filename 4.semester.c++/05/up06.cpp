/*
Даны классы Figure, Rectangle, Square, Circle (см. предыдущие задачи).
Дополнительно для всех фигур определен метод to_string, который возвращает строку std::string, описывающую данную фигуру.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>

bool compare(const Figure *f, const Figure *s) {
    return s->get_square() > f->get_square();
}

int main() {
    std::vector<Figure *> v;
    std::string in;
    while(std::getline(std::cin, in)) {
        while(in[0] != 'R' && in[0] != 'S' && in[0] != 'C') {
            in.erase(0, 1);
        }
        switch(in[0]) {
        case 'R':
            Rectangle *r;
            in.erase(0, 1);
            r = Rectangle::make(in);
            v.push_back(r);
            break;
        case 'S':
            Square *s;
            in.erase(0, 1);
            s = Square::make(in);
            v.push_back(s);
            break;
        case 'C':
            Circle *c;
            in.erase(0, 1);
            c = Circle::make(in);
            v.push_back(c);
            break;
        default:
            break;
        }
    }
    std::stable_sort(v.begin(), v.end(), compare);
    for(Figure *pt : v) {
        std::cout << pt->to_string() << std::endl;
    }
    for(Figure *pt : v) {
        delete pt;
    }
    return 0;
}