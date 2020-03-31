/*
Программе на стандартном потоке ввода подаётся последовательность вещественных чисел — результат серии экспериментов. 
Последовательность содержит не менее 10 чисел. 
Вычислите и выведите на стандартный поток вывода среднее арифметическое для нормализованной выборки. 
Вещественные числа должны быть напечатаны с 10 десятичными знаками после точки.
Нормализованная выборка — это выборка, у которой отброшены первые и последние 10% измерений (при вычислении 10% дробная часть отбрасывается), 
затем у оставшейся выборки отбрасываются 10% минимальных и максимальных значений 
(вычисление 10% ведется от оставшейся после первого отбрасывания части выборки, дробная часть при этом отбрасывается). 
Итого, в вычислениях участвует 64% от исходной выборки.
Для вычисления среднего арифметического используйте алгоритм for_each. 
Не используйте глобальные переменные. 
Прочие решения будут дисквалифицированы.
Обратите внимание, что алгоритм for_each возвращает в качестве результата класс-функтор, переданный ему третьим параметром. 
Это можно использовать для накопления результата вычисления в классе-функторе.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iostream>

class Sum {
    double n = 0;
    double sum = 0;
public:
    explicit Sum(double t) : sum(t) {}
    double median() {
        return sum / n;
    }
    void operator() (double element) {
        ++n;
        sum += element;
    }
};

int main() {
    Sum s(0);
    using namespace std;
    double dbuf;
    vector<double> v;
    constexpr double DIFFERENCE = 0.1;
    constexpr double SDIFFERENCE = DIFFERENCE;
    while(cin >> dbuf) {
        v.emplace_back(dbuf);
    }
    auto lastpos = v.end() - v.size() * DIFFERENCE;
    auto startpos = v.begin() + v.size() * DIFFERENCE;
    sort(startpos, lastpos);
    s = for_each(distance(startpos, lastpos) * SDIFFERENCE + startpos,
        lastpos - SDIFFERENCE * distance(startpos, lastpos), s);
    cout << setprecision(10) << s.median() << endl;
    return 0;
}