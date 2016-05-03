#include "rational.h"

using namespace std;

void Rational::setNum(int num) {
    this->num = num;
}

void Rational::setDen(int den) {
    if (den != 0) {
        this->den = den;
    } else {
        // Throw an exception
    }
}

int Rational::getNum() {
    return this->num;
}

int Rational::getDen() {
    return this->den;
}

int Rational::smaller(int& a, int& b) {
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
