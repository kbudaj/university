#include <iostream>
#include "rational.h"

using namespace std;

int main() {
    Rational a = Rational(1, 3);
    cout << a.getNum() << "/" << a.getDen() << endl;
    Rational b = Rational(2, -7);
    cout << b.getNum() << "/" << b.getDen() << endl;
    return 0;
}
