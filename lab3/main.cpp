#include "BigInt.h"
#include <fstream>

int main() {
    BigInt e("123");


    // тест вывода в консоль 
    std::cout << e << std::endl;   

    // Запись в текстовый файл
    std::ofstream foutText("number.txt");
    foutText << e;
    foutText.close();

    // Запись в двоичный файл
    std::ofstream foutBin("number.bin", std::ios::binary);
    e.writeBinary(foutBin);
    foutBin.close();

    // Чтение из двоичного файла
    BigInt f;
    std::ifstream finBin("number.bin", std::ios::binary);
    f.readBinary(finBin);
    finBin.close();

    std::cout << "Прочитано из бинарного файла: " << f << std::endl;



    return 0;
}
