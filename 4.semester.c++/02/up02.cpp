/*
В пространстве имен numbers реализуйте класс complex_stack, который будет реализовывать функциональность стека комплексных чисел из предыдущей задачи.
Реализация не должна использовать стандартные контейнерные классы (vector, stack и т. п.).
Для реализации стека используйте расширяемый массив, который реализуйте с помощью new и delete. 
Как обычно, расширяемый массив должен расширяться не на один, а в некторое число раз (размер умножается на 2 или 1.5).
Класс должен реализовывать:
конструктор по умолчанию.
конструкторы, деструкторы и операции, необходимые для корректного управления памятью.
метод size для получения числа элементов в стеке (возвращает size_t).
доступ к произвольному элементу стека с помощью операции [].
бинарный оператор <<, у которого первый аргумент - complex_stack, а второй аргумент - complex, бинарный оператор возвращает новый стек, в который добавлен указанный элемент. Исходный стек не изменяется.
унарный оператор +, который возвращает элемент типа complex с вершины стека.
унарный оператор ~, который удаляет один элемент из стека и возвращает модифицированный стек, исходный стек при этом не изменяется.
На проверку сдавайте только класс complex_stack.
Возможные ошибки (извлечение из пустого стека, доступ за пределами стека) игнорируйте.
Автор: Владимир (vk.com/yapoxe) 
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

namespace numbers {
    class complex_stack {
    private:
        int top = 0, number = 0;
        complex *array = 0;
    public:
        complex_stack(int cx = 32): top(-1), number(cx) {
            array = new complex[number];
        }
        complex_stack(const complex_stack &cs): top(cs.top), number(cs.number) {
            array = new complex[number];
            int i = 0;
            for(i = 0; i < top + 1; i++) {
                array[i] = cs.array[i];
            }
        }
        ~complex_stack() {
            delete[] array;
        }
        size_t size() const {
            return size_t(top + 1);
        }
        complex operator[](int n) const {
            return array[n];
        }
        complex operator+() const {
            return array[top];
        }
        complex_stack operator<<(const complex cx) const {
            int a = 0, i = 0;
            if ((top + 1) == number) {
                a = number * 2;
            } else {
                a = number;
            }
            complex_stack st(a);
            for(i = 0; i < top + 1; i++) {
                st.array[i] = array[i];
            }
            st.top = top + 1;
            st.array[st.top] = cx;
            return st;
        }
        complex_stack operator~() const {
            complex_stack st(*this);
            st.top = top - 1;
            return st;
        }
        complex_stack& operator=(const complex_stack &cs) {
            if (number < cs.number) {
                delete[] array;
                array = new complex[cs.number];
            }
            number = cs.number;
            top = cs.top;
            int i = 0;
            for(i = 0; i < top + 1; i++) {
                array[i] = cs.array[i];
            }
            return *this;
        }
    };
}