/*
Напишите функцию-шаблон process от одного параметра-типа: контейнера STL с двунаправленным итератором. 
Функция должна вернуть сумму трех последних элементов (если таковые имеются), 
если есть только два элемента, должна вычисляться их сумма и т. п.
Автор: Владимир (vk.com/yapoxe) 
*/
template <class Container>

typename Container::value_type process(const Container &x, int n = 3) {
    auto currentpos = x.rbegin();
    auto endpos = x.rend();
    int count = 1;
    if (endpos == currentpos) {
        return typename Container::value_type();
    } else {
        typename Container::value_type temp(*currentpos);
        while ((++count <= n) && (++currentpos != endpos)) {
            temp += *currentpos;
        }
        return temp;
    }
}