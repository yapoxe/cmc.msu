/*
В пространстве имен numbers реализуйте класс функцию eval с прототипом:
complex eval(char **args, const complex &z);
Функции подается на вход польская инверсная запись выражения над комплексными числами с одной переменной и значение переменной. 
В качестве результата функция возвращает вычисленное значение.
Возможные ошибки при вычислении игнорируйте.
Ваша реализация должна использовать ваши классы complex и complex_stack, которые вы должны сдать вместе с функцией eval.
В польской записи допускаются следующие элементы:
Запись комплексного числа в виде (RE,IM) (см. предыдущие задачи).
Обозначение переменной "z" (строчная латинская буква).
Знаки бинарных операций +, -, *, /.
Знак унарной операции !, которая заносит в стек элемент, находящийся на верхушке стека.
Знак унарной операции ;, которая удаляет элемент с верхушки стека.
Знак унарной операции ~, которая вычисляет комплексно-сопряженное число.
Знак унарной операции #, которая меняет знак у числа.
Массив аргументов args завершается нулевым указателем.
Обратите внимание, что польская запись z1 z2 - обозначает (z1 - z2), а не (z2 - z1)!
Каждая строка в массиве строк содержит ровно один элемент польской записи. Пробельные символы отсутствуют.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

namespace numbers
{
    class complex {
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
    class complex_stack {
    private:
        int top, number;
        complex *array = 0;
    public:
        complex_stack(int cx = 32): top(-1), number(cx) {
            array = new complex[number];
        }
        complex_stack(const complex_stack &cs): top(cs.top), number(cs.number) {
            array = new complex[number];
            memcpy(array, cs.array, sizeof(*array) * (top + 1));
        }
        ~complex_stack() {
            delete[] array;
        }
        size_t size() const {
            return size_t(top + 1);
        }
        complex operator[](int n) const {
            return array[n];
        }
        complex operator+() const {
            return array[top];
        }
        complex_stack operator<<(const complex cx) const {
            int a = 0;
            if ((top + 1) == number) {
                a = number * 2;
            } else {
                a = number;
            }
            complex_stack st(a);
            memcpy(st.array, array, (top + 1) * sizeof(*st.array));
            st.top = top + 1;
            st.array[st.top] = cx;
            return st;
        }
        complex_stack operator~() const {
            complex_stack st(*this);
            st.top = top - 1;
            return st;
        }
        complex_stack& operator=(const complex_stack &cs) {
            if (number < cs.number) {
                delete[] array;
                array = new complex[cs.number];
            }
            number = cs.number;
            top = cs.top;
            memcpy(array, cs.array, (top + 1) * sizeof(*array));
            return *this;
        }
    };
    complex eval(char **args, const complex &z) {
        int i = 0;
        complex b;
        complex_stack a;
        while (args[i] != 0) {
            switch (args[i][0]) {
            case '(':
                a = a << complex(args[i]);
                break;
            case 'z':
                a = a << z;
                break;
            case '!':
                a = a << +a;
                break;
            case ';':
                a = ~a;
                break;
            case '~':
                b = ~a[a.size() - 1];
                a = ~a;
                a = a << b;
                break;
            case '#':
                b = -a[a.size() - 1];
                a = ~a;
                a = a << b;
                break;
            case '+':
                b = a[a.size() - 1] + a[a.size() - 2];
                a = ~a;
                a = ~a;
                a = a << b;
                break;
            case '-':
                b = a[a.size() - 2] - a[a.size() - 1];
                a = ~a;
                a = ~a;
                a = a << b;
                break;
            case '*':
                b = a[a.size() - 1] * a[a.size() - 2];
                a = ~a;
                a = ~a;
                a = a << b;
                break;
            case '/':
                b = a[a.size() - 2] / a[a.size() - 1];
                a = ~a;
                a = ~a;
                a = a << b;
                break;
            default:
                break;
            }
            i++;
        }
        return +a;
    }
}