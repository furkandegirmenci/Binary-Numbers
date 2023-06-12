#ifndef _BINARYNUMBER_H
#define _BINARYNUMBER_H


class BinaryNumber {
    friend std::istream &operator>>(std::istream &is, BinaryNumber &rhs);
    friend std::ostream &operator<<(std::ostream &os, BinaryNumber &rhs);

private:
    int num;
    std::string total;
public:
    BinaryNumber operator+(BinaryNumber &rhs) const;

    BinaryNumber();
    BinaryNumber(unsigned long sum);
    BinaryNumber(std::string const str);


    ~BinaryNumber();
};


#endif //_BINARYNUMBER_H
