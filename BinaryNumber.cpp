#include <istream>
#include "BinaryNumber.h"
#include <bitset>

/*
 * Setting std::cin to take the whole line and turn the string line into only 0 and 1 string(no space allowed)
 * And add our binary number into bitset and set the object's integer number
 */
std::istream &operator>>(std::istream &is, BinaryNumber &rhs) {
    std::string str;
    std::getline(is, str);

    std::string intStr;
    for (auto i: str) {
        if(i == '0' || i == '1') {
            intStr += i;
        } else if(i == ' '){
            continue;
        } else {
            throw 0;
        }
    }
    std::bitset<9> binaryNum(intStr);

    // setting the integer number of the object
    rhs = BinaryNumber{binaryNum.to_ulong()};

    return is;
}


std::ostream &operator<<(std::ostream &os, BinaryNumber &rhs) {
    os << rhs.total;
    return os;
}

/*
 * Sum of two binary numbers that were given
 */
BinaryNumber BinaryNumber::operator+(BinaryNumber &rhs) const{
    std::bitset<9> binary1(num);
    std::bitset<9> binary2(rhs.num);
    std::bitset<9> sum = binary1.to_ulong() + binary2.to_ulong();
/*
 *   Sending to constructor for setting the number we have as binary insted of
 *   bitset library will return us the number as binary if we use to_string() method
*/
    return BinaryNumber(sum.to_string());
}


BinaryNumber::BinaryNumber() : num{0} {}
BinaryNumber::BinaryNumber(unsigned long sum) : num{static_cast<int>(sum)}  {}
// Setting the sum of two binary numbers as total
BinaryNumber::BinaryNumber(std::string const str){
    total = str;

    // For making sure we have spaces between every 4 bits
    for (int i = 8; i > 0 ; i--) {
        if(i % 4 == 1) {
            total.insert(i, " ");
        }
    }
    if(total.at(0) == '0') {
        total.erase(0, 2);
    }
}



BinaryNumber::~BinaryNumber() {}