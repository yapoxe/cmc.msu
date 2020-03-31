/*
В пространстве имен numbers реализуйте класс complex для комплексных чисел над типом double. Класс должен определять:
Конструкторы по умолчанию, от одного и двух аргументов. Должен реализовываться одним конструктором.
Явный (explicit) конструктор из типа const char *, который преобразовывает строку в стиле Си. 
Строка имеет формат (RE,IM), то есть вещественная и мнимая части (числа типа double) записываются через запятую в круглых скобках. 
Например, строка "(1.0,-5)" определяет комплексное число (1.0,-5.0).
Методы get_re и get_im для получения вещественной и мнимой части числа.
Метод abs2 для получения квадрата модуля числа.
Метод abs для получения модуля числа.
Метод to_string с аргументами (char *buf, size_t size), который преобразовывает комплексное число в строковое представление (см. выше) 
и сохраняет результат в переданном буфере. Вещественные числа выводятся с 10 значащими цифрами в формате %.10g.
Операции сложения, вычитания, умножения и деления в обычной инфиксной форме.
Префиксную операцию ~, которая возвращает новое число, комплексно-сопряженное к аргументу.
Префиксную операцию - смены знака.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <cstdio>
#include <iostream>
#include <cmath>

namespace numbers
{
    class complex
    {
    private:
        double x = 0, y = 0;
    public:
        complex(double arg1 = 0, double arg2 = 0): x(arg1), y(arg2) {}
        explicit complex(const char *str) {
            std::sscanf(str, "(%lf, %lf)", &x, &y);
        }
        double get_im(void) const {
            return y;
        }
        double get_re(void) const {
            return x;
        }
        double abs(void) const {
            return std::sqrt(x * x + y * y);
        }
        double abs2(void) const {
            return (x * x + y * y);
        }
        void to_string(char *buf, size_t size) const {
            snprintf(buf, size, "(%.10g,%.10g)", x, y);
        }
        friend complex operator- (const complex &a, const complex &b) {
            return complex(a.x - b.x, a.y - b.y);
        }
        friend complex operator+ (const complex &a, const complex &b) {
            return complex(a.x + b.x, a.y + b.y);
        }
        friend complex operator* (const complex &a, const complex &b) {
            return complex(a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y);
        }
        friend complex operator/ (const complex &a, const complex &b) {
            return complex((a.x * b.x + a.y * b.y) / b.abs2(), (a.y * b.x - a.x * b.y) / b.abs2());
        }
        friend complex operator- (const complex &a) {
            return complex(-a.x, -a.y);
        }
        friend complex operator~ (const complex &a) {
            return complex(a.x, -a.y);
        }
    };
}