/*
Напишите программу, которая выполняет RLE-кодирование стандартного потока ввода.
При RLE (run length encoding) кодировании последовательность одинаковых идущих подряд символов заменяется на специальный маркер с длиной последовательности.
Последовательности одинаковых символов длиной не более 4 остаются без изменений (кроме символа '#'). 
Последовательности одинаковых символов длиной более 4 заменяются на последовательность символов '#', CHAR, N, '#', 
где CHAR — это символ, N — число повторений, записываемое в текстовом виде в шестнадцатеричной системе счисления с цифрами 0-9 и a-f.
Последовательность символов '#' любой длины кодируется всегда как описано выше.

Использовать ввод-вывод языка Си++.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>

int main() {
    int c = 0;
    int i = 0;
    int count = 1;
    int prev = std::cin.get();
    if(prev == EOF) {
        return 0;
    }
    do{
        c = std::cin.get();
        if(prev == c) {
            ++count;
        } else if (count < 5 && prev != '#') {
            for(i = 1; i <= count; i++) {
                std::cout << static_cast<unsigned char>(prev);
            }
            count = 1;
        } else {
            std::cout << '#' << static_cast<unsigned char>(prev) << std::hex << count << '#';
            count = 1;
        }
        prev = c;
    } while (c != EOF);
    return 0;
}