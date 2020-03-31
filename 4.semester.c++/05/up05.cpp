/*
Дан абстрактный класс Figure (см. предыдущую задачу).
Опишите классы Rectangle, Square, Circle, наследующие класс Figure. 
Классы должны хранить параметры фигуры, а площадь каждый раз должна вычисляться. 
Для окружности хранится ее радиус.
Для создания объектов соответствующих классов каждый класс должен определять статический метод make, 
который в качестве параметра принимает строку std::string. Метод make возвращает указатель на объект, созданный в куче.
Для класса Rectangle строка содержит два вещественных числа, разделенных пробелами, а для классов Square и Circle — одно вещественное число.
За ошибки компиляции будут сниматься баллы.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <cstring>
#include <cmath>
#include <iostream>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

class Rectangle : public Figure {
private:
    double l = 0, w = 0;
public:
    static Rectangle *make(const std::string &str)
    {
        Rectangle *n = new Rectangle;
        sscanf(str.c_str(), "%lf%lf", &n->l, &n->w);
        return n;
    }
    double get_square() const override
    {
        return l * w;
    }
};

class Square : public Figure {
private:
    double l = 0;
public:
    static Square *make(const std::string &str)
    {
        Square *n = new Square;
        sscanf(str.c_str(), "%lf", &n->l);
        return n;
    }
    double get_square() const override
    {
        return l * l;
    }
};

class Circle : public Figure {
private:
    double r = 0;
public:
    static Circle *make(const std::string &str)
    {
        Circle *n = new Circle;
        sscanf(str.c_str(), "%lf", &n->r);
        return n;
    }
    double get_square() const override
    {
        return M_PI * r * r;
    }
};