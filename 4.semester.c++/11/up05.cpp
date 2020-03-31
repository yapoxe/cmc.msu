/*
На стандартный поток ввода программе подаётся выражение в польской записи. 
Выражение может содержать имена переменных и бинарные операции +, -, *, /. 
Имя переменной — это строчная латинская буква. 
Элементы ввода могут разделяться произвольным количеством пробельных символов.
Напечатайте введённое выражение в инфиксной записи. 
Для сохранения приоритетов бинарные операции заключите в скобки. 
Выражение напечатайте в одной строке текста без пробельных символов.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>
#include <string>
#include <stack>

bool check(char c) {
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    } else {
        return 0;
    }
}

std::string getexp(std::string s) {
    std::stack<std::string> str;
    int i = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (check(s[i])) {
            std::string op(1, s[i]);
            str.push(op);
        } else {
            std::string t1 = str.top();
            str.pop();
            std::string t2 = str.top();
            str.pop();
            str.push("(" + t2 + s[i] + t1 + ")");
        }
    }
    return str.top();
}

int main() {
    std::string str;
    getline(std::cin, str);
    std::cout << getexp(str) << std::endl;
    return 0;
}