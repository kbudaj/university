//
// Created by kb on 5/3/16.
//

#ifndef ZAD7_RATIONAL_H
#define ZAD7_RATIONAL_H

#include <cmath>
#include <iostream>
#include <set>

using namespace std;

class Rational {
    // Numinator, Denominator
    int num, den;

    void simplify();
    int smaller(int a, int b);

public:
    Rational(int num);
    Rational(int num, int den);
    void setNum(int num);
    void setDen(int den);
    int getNum();
    int getDen();

    Rational& operator=(const Rational& obj) = default;
    Rational(const Rational& obj) = default;

    // Arithmetics
    friend ostream& operator<<(ostream& out, const Rational& r);
    friend Rational operator+(const Rational& a, const Rational& b);
    friend Rational operator-(const Rational& a, const Rational& b);
    friend Rational operator*(const Rational& a, const Rational& b);
    friend Rational operator/(const Rational& a, const Rational& b);
    friend Rational operator-(const Rational& a);
    friend Rational operator!(const Rational& a);

    // Cast to double
    operator double() const;
    // Cast to int
    operator int() const;


};

#endif //ZAD7_RATIONAL_H
