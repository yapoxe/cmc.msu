/*
Дано прямоугольное поле размером m строк на n столбцов клеток. 
Левая нижняя клетка поля имеет координаты (0,0), правая верхняя клетка поля — (m - 1,n - 1).
Поле закольцовано в тор, то есть склеены верхняя и нижняя границы поля и правая и левая границы поля.
Из некоторой клетки можно перейти за один ход в любую из четырех соседних клеток (если таковые существуют). 
Например, из клетки (1,2) можно перейти в клетки (0,2), (2,2), (1,1), (1,3).
Расстояние между двумя клетками — это минимальное число ходов, за которое можно перейти из одной клетки в другую.
На стандартном потоке ввода задаются два целых числа m и n, задающие размеры поля.
Далее вводятся четверки целых чисел r1, c1, r2, c2, задающие координаты (r1,c1) первой и (r2,c2) второй клеток.
Для каждой четверки координат выведите на стандартный поток вывода расстояние между этими клетками.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>
int main() {
    int r1, c1, r2, c2, m, n;
    std::cin >> m >> n;
    while(std::cin >> r1 >> c1 >> r2 >> c2) {
        std::cout << std::min(m - abs(r1 - r2), abs(r1 - r2)) + std::min(n - abs(c1 - c2), abs(c1 - c2))<< std::endl;
    }
    return 0;
}