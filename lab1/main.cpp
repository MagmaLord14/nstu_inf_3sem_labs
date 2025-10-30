#include "BigInt.h"

int main() {
    BigInt a;                      // Конструктор по умолчанию
    BigInt b("123456789012345678"); // Конструктор с параметром
    BigInt c = b;                  // Конструктор копирования

    std::cout << "Number a: "; a.print();
    std::cout << "Number b: "; b.print();
    std::cout << "Number c: "; c.print();

    a.setValue("9876543210987654321");
    std::cout << "Updated number a: "; a.print();

    BigInt sum = a.add(b);
    std::cout << "Sum of a and b: "; sum.print();

    return 0;
}
