/*
На вход подается описание КС-грамматики в следующем формате:
<левая часть> <правая часть>
где <...> – строки, состоящие из цифр, строчных и заглавных латинских символов, а также символа ‘_’, означающего пустую цепочку (эпсилон).
Строчные символы и цифры – терминальные (из Т).
Заглавные – нетерминальные (из N).
Правила грамматики задаются не в сокращенной форме.
На выходе программа должна вывести:
правила эквивалентной грамматики без недостижимых символов не в сокращенной форме.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <vector>
#include <algorithm>
#include <iostream>

struct Grammar {
    std::string lt, rt;
    Grammar(std::string &l, std::string &r) {
        lt = l;
        rt = r;
    }
};

int main() {
    std::vector <std::string> v, vPr;
    std::vector <Grammar> g;
    std::string fstr, sstr;
    v.push_back("S");
    while(std::cin >> fstr >> sstr) {
        g.push_back(Grammar(fstr, sstr));
    }
    do{
        vPr = v;
        auto pt = g.begin();
        for(pt = g.begin(); pt != g.end(); pt++) {
            auto f = std::find(v.begin(), v.end(), pt->lt);
            if(f != v.end()) {
                for(auto j = pt->rt.begin(); j != pt->rt.end(); j++) {
                    if(*j <= 'Z' && *j >= 'A') {
                        v.push_back(std::string(1, *j));
                    }
                }
            }
        }
        std::sort(v.begin(), v.end());
        auto end = std::unique(v.begin(), v.end());
        v.erase(end, v.end());
    } while(vPr != v);
    auto pt = g.begin();
    while(pt != g.end()) {
        auto f = std::find(v.begin(), v.end(), pt->lt);
        if(f == v.end()) {
            pt = g.erase(pt);
        } else {
            ++pt;
        }
    }
    for(pt = g.begin(); pt != g.end(); pt++) {
        std::cout << pt->lt << ' ' << pt->rt << std::endl;
    }
    return 0;
}