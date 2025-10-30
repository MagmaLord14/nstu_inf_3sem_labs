#include "BigInt.h"

// по умолчанию
BigInt::BigInt() {
    digits = new char[2];
    strcpy(digits, "0");
    length = 1;
}

// с параметром
BigInt::BigInt(const char* value) {
    length = strlen(value);
    digits = new char[length + 1];
    strcpy(digits, value);
}

// копирования
BigInt::BigInt(const BigInt& other) {
    length = other.length;
    digits = new char[length + 1];
    strcpy(digits, other.digits);
}

// Деструктор
BigInt::~BigInt() {
    delete[] digits;
}

// Установка значения
void BigInt::setValue(const char* value) {
    delete[] digits;
    length = strlen(value);
    digits = new char[length + 1];
    strcpy(digits, value);
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

// Метод присваивания
BigInt& BigInt::operator=(const BigInt& other) {
    if (this != &other) {
        delete[] digits;
        length = other.length;
        digits = new char[length + 1];
        strcpy(digits, other.digits);
    }
    return *this;
}

// Вычитание (дружественная функция)
BigInt operator-(const BigInt& a, const BigInt& b) {
    int num1 = atoi(a.digits);
    int num2 = atoi(b.digits);
    int diff = num1 - num2;

    char buffer[100];
    sprintf(buffer, "%d", diff);
    return BigInt(buffer);
}

BigInt& BigInt::operator++() {
    *this = this->add(BigInt("1"));
    return *this; 
}

// Постфиксный инкремент (x++)
BigInt BigInt::operator++(int) {
    BigInt temp(*this);
    *this = this->add(BigInt("1"));  
    return temp;
}

// Приведение к типу int
BigInt::operator int() const {
    return atoi(digits);
}


void BigInt::print() const {
    cout << digits << endl;
}
