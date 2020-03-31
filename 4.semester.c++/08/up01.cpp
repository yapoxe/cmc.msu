/*
Дан язык L={αβ}, где α={3,4}n, β={1,2}m, n >= 0, m >= 0.
На стандартном потоке подаются строки, разделяющиеся пробельными символами. 
Для каждой строки на стандартный поток вывода напечатайте 1, если строка принадлежит языку, и 0 в противном случае.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>

int main() {
    std::string s;
    int tr = 1;
    int fl = 0;
    while(std::cin >> s) {
        auto pt = s.begin();
        auto end = s.end();
        tr = 1;
        fl = false;
        while(pt != end) {
            switch (*pt) {
                case '3' :
                    if(fl == 2) {
                        tr = 0;
                    } else {
                        fl = 1;
                    }
                    break;
                case '4' :
                    if(fl == 2) {
                        tr = 0;
                    } else {
                        fl = 1;
                    }
                    break;
                case '1' :
                    fl = 2;
                    break;
                case '2' :
                    fl = 2;
                    break;
                default:
                    tr = 0;
                    break;
            }
            ++pt;
        }
        std::cout << tr << std::endl;
    }
    return 0;
}