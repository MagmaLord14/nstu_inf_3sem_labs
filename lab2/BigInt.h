#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <cstring>
using namespace std;

class BigInt {
private:
    char* digits; // строка с цифрами
    int length;   // длина числа

public:
    BigInt();                       // по умолчанию
    BigInt(const char* value);      // с параметром
    BigInt(const BigInt& other);    // копирования
    ~BigInt();

    // Методы
    void setValue(const char* value);
    void print() const;

    // ------------------------------
    // Переопредление операций
    // ------------------------------

    friend BigInt operator-(const BigInt& a, const BigInt& b);
    

    BigInt add(const BigInt& other) const;

    BigInt& operator=(const BigInt& other);

    // Префиксный инкремент (++x)
    BigInt& operator++();

    // Постфиксный инкремент (x++)
    BigInt operator++(int);

    // Приведение к типу int
    operator int() const;
};

#endif
