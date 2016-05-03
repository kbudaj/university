//
// Created by kb on 5/3/16.
//

#ifndef ZAD7_RATIONAL_H
#define ZAD7_RATIONAL_H

#include <cmath>

class Rational {
    // Numinator, Denominator
    int num, den;
    // Operations
    friend Rational operator+(const Rational& a, const Rational& b);
    friend Rational operator-(const Rational& a, const Rational& b);
    friend Rational operator*(const Rational& a, const Rational& b);
    friend Rational operator*(const Rational& a, const Rational& b);
    friend Rational operator/(const Rational& a, const Rational& b);
    //friend Rational operator-();
    //friend Rational operator!() const;
    void simplify();
    int smaller(int& a, int& b);

public:
    Rational(int num);
    Rational(int num, int den);
    void setNum(int num);
    void setDen(int den);
    int getNum();
    int getDen();
};

#endif //ZAD7_RATIONAL_H
