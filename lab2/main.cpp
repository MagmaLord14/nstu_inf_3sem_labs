#include "BigInt.h"

int main() {
    BigInt a("123");
    BigInt b("77");

    cout << "a = "; a.print();
    cout << "b = "; b.print();

    cout << "\nСложение (a.add(b)): ";
    BigInt c = a.add(b);
    c.print();

    cout << "Вычитание (a - b): ";
    BigInt d = a - b;
    d.print();

    cout << "\nПроверка присваивания: ";
    BigInt e;
    e = c;
    e.print();

    cout << "\nПрефиксный инкремент (++e): ";
    ++e;
    e.print();

    cout << "Постфиксный инкремент (e++): ";
//    e++;
    e++.print();

    cout << "\nПриведение к типу int: ";
    int x = e;
    cout << x << endl;

    return 0;
}
