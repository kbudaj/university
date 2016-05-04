#include <iostream>
#include "rational.h"

using namespace std;

void Rational::setNum(int num) {
    this->num = num;
}

void Rational::setDen(int den) {
    if (den != 0) {
        this->den = den;
    } else {
        throw domain_error("Can't create rational number with denominator = 0.");
    }
}

int Rational::getNum() {
    return this->num;
}

int Rational::getDen() {
    return this->den;
}

int Rational::smaller(int a, int b) {
    // This returns smaller of abs(a) and abs(b)
    a = abs(a);
    b = abs(b);
    if (a >= b) {
        return b;
    } else {
        return a;
    }
}

void Rational::simplify() {
    int smaller = Rational::smaller(num, den);

    for (int i=2; i<=smaller; i++) {
        while (num%i == 0 && den%i == 0) {
            num = num/i;
            den = den/i;
            smaller = Rational::smaller(num, den);
        }
    }

    if (num != abs(num) && den != abs(den)) {
        num = abs(num);
        den = abs(den);
    } else if (den != abs(den)) {
        num = (-1)*num;
        den = abs(den);
    }
}

Rational::Rational(int num) {
    setNum(num);
    setDen(1);
}

Rational::Rational(int num, int den) {
    setNum(num);
    setDen(den);
    simplify();
}

ostream& operator<<(ostream& out, const Rational& r) {
    // out << r.num;
    // if (r.den != 1) {
    //     out << "/" << r.den;
    // }
    // return out;
    // double a, b;
    // int rest, k;
    // set<int> record;
    //
    // for (int i=0; i<100; i++) {
    //     k = a/b;
    //     cout << k;
    //     out << k;
    //     break;
    // }

    return out;
}

Rational operator+(const Rational& a, const Rational& b) {
    int new_num = a.num * b.den + b.num * a.den;
    int new_den = a.den * b.den;
    Rational result = Rational(new_num, new_den);
    return result;
}

Rational operator-(const Rational& a, const Rational& b) {
    int new_num = a.num * b.den - b.num * a.den;
    int new_den = a.den * b.den;
    Rational result = Rational(new_num, new_den);
    return result;
}

Rational operator*(const Rational& a, const Rational& b) {
    int new_num = a.num * b.num;
    int new_den = a.den * b.den;
    Rational result = Rational(new_num, new_den);
    return result;
}

Rational operator/(const Rational& a, const Rational& b) {
    int new_num = a.num * b.den;
    int new_den = a.den * b.num;
    Rational result = Rational(new_num, new_den);
    return result;
}

Rational operator-(const Rational& a) {
    int new_num = (-1) * a.num;
    int new_den = a.den;
    Rational result = Rational(new_num, new_den);
    return result;
}

Rational operator!(const Rational& a) {
    int new_num = a.den;
    int new_den = a.num;
    Rational result = Rational(new_num, new_den);
    return result;
}

Rational::operator double() const {
    double a = this->num;
    double b = this->den;
    return a/b;
}

Rational::operator int() const {
    double a = this->num;
    double b = this->den;
    double result = a/b;
    return round(result);
}
