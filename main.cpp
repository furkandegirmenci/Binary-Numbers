#include <iostream>
#include "BinaryNumber.h"

int main() {

    std::cout << "Binary Sayı Toplama\n"
                 "Birini binary sayısı giriniz :";
    BinaryNumber binary1;
    std::cin >> binary1;

    std::cout << "İkinci binary sayısı giriniz :";
    BinaryNumber binary2;
    std::cin >> binary2;

    BinaryNumber sum = binary1 + binary2;


    std::cout << "Binary toplamı sonucu :" << sum;

    return 0;
}
