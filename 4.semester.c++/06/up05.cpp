/*
Дано прямоугольное поле размером m строк на n столбцов клеток. 
Левая нижняя клетка поля имеет координаты (0,0), правая верхняя клетка поля — (m - 1,n - 1).
Поле закольцовано в тор, то есть склеены верхняя и нижняя границы поля и правая и левая границы поля.
Из некоторой клетки можно перейти за один ход в любую из восьми соседних клеток.
Например, из клетки (1,2) можно перейти в клетки (0,2), (2,2), (1,1), (1,3), (0, 1), (0, 3), (2, 1), (2, 3).
Расстояние между двумя клетками — это минимальное число ходов, за которое можно перейти из одной клетки в другую.
Напишите шаблонный класс Coord, параметризованный типом координат. 
Класс должен содержать открытый тип value_type, открытые поля row, col и открытый конструктор от 0, 1 или 2 аргументов.
Напишите шаблонну функцию dist, принимающую три параметра: размеры поля, две координаты клеток, которая вычисляет расстояние между двумя клетками.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>

template <typename A>
class Coord {
public:
    typedef A value_type;
    A row, col;
    Coord(A r, A c): row(r), col(c) {}
};

template <typename A>
A dist(Coord<A> &size, Coord<A> &fpos, Coord<A> &spos) {
    A hor1 = std::abs(fpos.row - spos.row);
    A hor2;
    if(spos.row > fpos.row) {
        hor2 = fpos.row + size.row - spos.row;
    } else {
        hor2 = spos.row + size.row - fpos.row;
    }
    A hor = std::min(hor1, hor2);
    A ver1 = std::abs(fpos.col - spos.col);
    A ver2;
    if(spos.col > fpos.col) {
        ver2 = fpos.col + size.col - spos.col;
    } else {
        ver2 = spos.col + size.col - fpos.col;
    }
    A ver = std::min(ver1, ver2);
    return std::max(ver, hor);
}