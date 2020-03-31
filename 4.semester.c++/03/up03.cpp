/*
На стандартном потоке ввода программе подаются слова. 
Слова разделяются произвольным количеством пробельных символов. 
Напечатайте самое длинное начало каждой строки, являющееся палиндромом. 
Каждую строку выводите на отдельной строке стандартного потока вывода.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string word;
    string r_word;
    while (cin >> word) {
        r_word = word;
        reverse(r_word.begin(), r_word.end());
        while (r_word != word) {
            word.erase(word.end() - 1);
            r_word.erase(r_word.begin());
        }
        cout << word << '\n';
    }
}