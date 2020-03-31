/*
На стандартном потоке ввода подаются два неотрицательных целых числа m и n. 
На стандартный поток вывода напечатайте значение функции Аккермана A(m, n).
Параметры на входе будут таковы, что вычисление завершится за разумное время. 
Для хранения значений достаточно типа int.
Для возврата значения из рекурсии используйте исключения. 
Напишите свой класс (например, Result) для передачи результата вычислений вместе с исключением. 
Не используйте выбрасывание исключений базовых (например, int) типов.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>

class Result {
private:
    int n;
public:
    Result(int a): n(a) {}
    int get() {
        return n;
    }
};

void ackermann(int m, int n) {
    if(!m) {
        throw Result(n + 1);
    }
    if(!n) {
        ackermann(m - 1, 1);
    }
    try {
        ackermann(m, n - 1);
    } catch (Result a) {
        ackermann(m - 1, a.get());
    }
}

int main() {
    int m, n;
    std::cin >> m >> n;
    try {
        ackermann(m, n);
    } catch (Result a) {
        std::cout << a.get() << std::endl;
    }
    return 0;
}