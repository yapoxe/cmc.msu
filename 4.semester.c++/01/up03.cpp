/*
Напишите класс Sum таким образом, чтобы конструкция Sum(a, b).get() 
возвращала сумму двух целых параметров a, b.
Автор: Владимир (vk.com/yapoxe) 
*/
class Sum {
    int n = 0, m = 0;
public:
    Sum(int x, int y): n(x), m(y) {}
    int get() const {
        return n + m;
    }
};