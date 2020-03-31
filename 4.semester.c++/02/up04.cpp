/*
Программе в аргументах командной строки передаются:
Комплексное число C.
Вещественное число R.
Целое число N.
Остальные аргументы - запись функции одного комплексного аргумента в польской записи.
На стандартный поток вывода напечатайте комплексное число I - результат вычисления криволинейного интеграла 
по замкнутому контуру - окружности с центром в точке C и радиусом R.
Для вычисления используйте метод прямоугольников. Для этого окружность делится на N частей.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

constexpr int STRING_SIZE = 256;

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
        int top = 0, number = 0;
        complex *array = 0;
    public:
        complex_stack(int cx = 32): top(-1), number(cx) {
            array = new complex[number];
        }
        complex_stack(const complex_stack &cs): top(cs.top), number(cs.number) {
            array = new complex[number];
            memcpy(array, cs.array, sizeof(*array) * (top + 1));
            int i = 0;
            for(i = 0; i < top + 1; i++) {
                array[i] = cs.array[i];
            }
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
            int a = 0, i = 0;
            if ((top + 1) == number) {
                a = number * 2;
            } else {
                a = number;
            }
            complex_stack st(a);
            for(i = 0; i < top + 1; i++) {
                st.array[i] = array[i];
            }
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
            int i = 0;
            for(i = 0; i < top + 1; i++) {
                array[i] = cs.array[i];
            }
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

using namespace numbers;

int main(int argc, char **argv)
{
    char str[STRING_SIZE];
    int i = 1;
    int n = std::stoi(argv[3]);
    double r = std::stod(argv[2]);
    complex c(argv[1]);
    complex z1(c.get_re() + r, c.get_im());
    complex answer;
    double additional_angle = 2 * (M_PI / n);
    double angle = 0;
    for (i = 1; i <= n; i++) {
        angle += additional_angle;
        complex z2(c.get_re() + r * cos(angle), c.get_im() + r * sin(angle));
        answer = answer + eval(argv + 4, z1) * (z2 - z1);
        z1 = z2;
    }
    answer.to_string(str, sizeof(str));
    std::cout << str << std::endl;
    return 0;
}