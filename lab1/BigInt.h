#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <cstring>
w
class BigInt {
private:
    int length;      // Длина числа
    char* digits;    // Массив символов числа

public:
    // Конструктор по умолчанию
    BigInt();

    // Конструктор с параметрами (инициализация строкой)
    BigInt(const char* numStr);

    // Конструктор копирования
    BigInt(const BigInt& other);

    // Деструктор
    ~BigInt();

    // Метод для изменения значения числа
    void setValue(const char* numStr);

    // Метод для сложения двух чисел
    BigInt add(const BigInt& other) const;

    // Метод для вывода числа
    void print() const;
};

#endif
