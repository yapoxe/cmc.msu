/*
Дан язык L={αβ}, где α={3,4}n, β={1,2}m, n >= 0, m >= 0.
На стандартном потоке подается целое число K (K >= 0). 
Выведите на стандартный поток вывода все цепочки языка L длины K в лексикографическом порядке. 
Каждую цепочку выводите на отдельной строке текста.
Не разрешается сохранять все цепочки длины K в памяти одновременно (например, для сортировки). 
Ваше решение не может требовать для работы память размера, более чем линейно зависящего от K (например, K^2).
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>

class L {
private:
    int lng;
    std::string s;
    bool check(int k) {
        int i = 0;
        for(i = 0; i < k; i++) {
            if(s[i] == '2' || s[i] == '1') {
                return true;
            }
        }
        return false;
    }
    bool change(int &k) {
        switch (s[k]) {
        case '1':
            s[k] = '2';
            break;
        case '2':
            s[k] = '3';
            if(check(k)) {
                return change(k);
            }
            break;
        case '3':
            s[k] = '4';
            if(check(k)) {
                return change(k);
            }
            break;
        case '4':
            s[k] = '1';
            return true;
        default:
            break;
        }
        return false;
    }
public:
    L(int n): lng(n) {
        s = std::string(unsigned(lng), '1');
    }
    std::string get() const {
        return s;
    }
    bool up() {
        bool f = true;
        int k = lng - 1;
        while(f) {
            f = change(k);
            k--;
            if(f && k == -1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int k;
    std::cin >> k;
    if(!k) {
        return 0;
    }
    L l(k);
    std::cout << l.get() << std::endl;
    while(l.up()) {
        std::cout << l.get() << std::endl;
    }
    return 0;
}