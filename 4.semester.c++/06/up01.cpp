/*
На стандартном потоке ввода подается последовательность целых чисел. 
Напечатайте эту последовательность в обратном порядке по одному числу на строку.
Не используйте ни массивов, ни других контейнерных классов. 
Выход из рекурсии должен выполняться с помощью исключения. 
Печать числа должна выполняться в деструкторе некоторого класса при обработке исключения (свертке стека).
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>

class A {
    int n = 0;
public:
    A(int initial = 0) : n(initial) {};
    ~A() {
        std::cout << n << std::endl;
    }
};

void func() {
    int x;
    try {
        if(std::cin >> x) {
            A n = A(x);
            func();
            throw 'a';
        }
    } catch(char a) {
        return;
    }
}

int main() {
    func();
    return 0;
}