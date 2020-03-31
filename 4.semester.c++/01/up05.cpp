/*
Реализовать пользовательский тип «Рациональные числа» (Rational).
// Создание объектов
Rational q = Rational(1, 3), w(1, 3);
Rational s = 4;
Rational z = q;

// Арифметические операции
s.Add(q);       // значение s увеличивается на значение q  
             // (значение s меняется)  
s.Substract(q); // значение s изменяется путем вычитания q  
s.Multiply(q);  // значение s изменяется путем домножения на q  
s.Divide(q);    // значение s изменяется путем деления на q  

s.Add(q).Multiply(w); // значение s меняется путем инкрементирования q  
                   // с последующим домножением на w  

// Логические операции
s.EqualTo(w); // возращает булево значение, равно ли значение s значению w
s.CompareTo(w); // возвращает целое > 0, если s > w,
                // иначе возвращает целое < 0, если s < w,
                // иначе возвращает 0
s.IsInteger()   // возвращает булево значение, является ли s целым числом

// Строковое представление в формате a:b
string str = w.ToString();  // вернет 1:3

// Создание массивов
Rational arr[10];
Автор: Владимир (vk.com/yapoxe) 
*/

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

class Rational
{
private:
    int a = 0;
    int b = 1;
public :
    static int nod(int a, int b)
    {
        int t;
        while (b != 0) {
            t = b;
            b = a % b;
            a = t;
        }
        return !a? 1: a;
    }
    void RationalUpdate()
    {
        int c = nod(a, b);
        a /= c;
        b /= c;
    }
    Rational(int x = 0, int y = 1): a(x), b(y) {
        RationalUpdate();
    }
    Rational(const Rational &r): a(r.a), b(r.b) {}
    Rational& Add(Rational r)
    {
        a = a * r.b + b * r.a;
        b *= r.b;
        RationalUpdate();
        return *this;
    }
    Rational& Substract(Rational r)
    {
        a = a * r.b - b * r.a;
        b *= r.b;
        RationalUpdate();
        return *this;
    }
    Rational& Multiply(Rational r)
    {
        a *= r.a;
        b *= r.b;
        RationalUpdate();
        return *this;
    }
    Rational& Divide(Rational r)
    {
        a *= r.b;
        b *= r.a;
        RationalUpdate();
        return *this;
    }
    bool EqualTo(const Rational r) const
    {
        return (a == r.a) && (b == r.b);
    }
    int CompareTo(const Rational r) const
    {
        return a * r.b - b * r.a;
    }
    bool IsInteger() const
    {
        return b == 1;
    }
    std::string ToString() const
    {
        return std::to_string(a) + std::string(":") + std::to_string(b);
    }
};