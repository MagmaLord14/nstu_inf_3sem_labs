#include "BigInt.h"
#include <algorithm>

// Конструктор по умолчанию
BigInt::BigInt() {
    length = 1;
    digits = new char[2]; // 1 символ + \0
    digits[0] = '0';
    digits[1] = '\0';
    std::cout << "Default constructor called\n";
}

// Конструктор с параметрами
BigInt::BigInt(const char* numStr) {
    length = std::strlen(numStr);
    digits = new char[length + 1];
    std::strcpy(digits, numStr);
    std::cout << "Parameterized constructor called\n";
}

// Конструктор копирования
BigInt::BigInt(const BigInt& other) {
    length = other.length;
    digits = new char[length + 1];
    std::strcpy(digits, other.digits);
    std::cout << "Copy constructor called\n";
}

// Деструктор
BigInt::~BigInt() {
    delete[] digits;
    std::cout << "Destructor called\n";
}

// Метод для изменения значения числа
void BigInt::setValue(const char* numStr) {
    delete[] digits;
    length = std::strlen(numStr);
    digits = new char[length + 1];
    std::strcpy(digits, numStr);
}

// Метод для сложения двух чисел
BigInt BigInt::add(const BigInt& other) const {
    int maxLength = std::max(length, other.length);
    char* result = new char[maxLength + 2]; // +1 на перенос, +1 на '\0'

    int carry = 0;
    int i = length - 1;
    int j = other.length - 1;
    int k = maxLength;

    result[k + 1] = '\0';

    while (k >= 0) {
        int digit1 = (i >= 0) ? digits[i] - '0' : 0;
        int digit2 = (j >= 0) ? other.digits[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[k] = (sum % 10) + '0';
        i--; j--; k--;
    }

    BigInt sumResult(result + (result[0] == '0' ? 1 : 0)); // убрать ведущий 0
    delete[] result;
    return sumResult;
}

// Метод для вывода числа
void BigInt::print() const {
    std::cout << digits << std::endl;
}
