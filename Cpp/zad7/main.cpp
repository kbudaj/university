#include <iostream>
#include "rational.h"

using namespace std;
using namespace obliczenia;

int main() {
    // Test Constructors
    cout << "  ---------------" << endl;
    cout << "--| Constructors |--" << endl;
    cout << "  ---------------" << endl;
    Rational a = Rational(1);
    cout << a << endl;
    Rational b = Rational(2, 7);
    cout << b << endl;
    Rational c = Rational(2, -4);
    cout << c << endl;
    Rational d = Rational(16, -2);
    cout << d << endl;
    Rational e = Rational(-2, -4);
    cout << e << endl << endl;

    // Copy constructor
    cout << "--( Copy )--" << endl;
    Rational copy1(a);
    cout << "Copy of " << a << " -> " << copy1 << endl;
    Rational copy2(b);
    cout << "Copy of " << b << " -> " << copy2 << endl;
    Rational copy3(c);
    cout << "Copy of " << c << " -> " << copy3 << endl;
    Rational copy4(d);
    cout << "Copy of " << d << " -> " << copy4 << endl;

    // Assign constructor
    cout << "--( Assign )--" << endl;
    Rational test = a;
    cout << "test = " << a << " ->  test = " << test << endl;
    test = b;
    cout << "test = " << b << " ->  test = " << test << endl;
    test = c;
    cout << "test = " << c << " ->  test = " << test << endl;
    test = d;
    cout << "test = " << d << " ->  test = " << test << endl;


    // Test Arithmetics
    cout << "  ---------------" << endl;
    cout << "--| Arithmetics |--" << endl;
    cout << "  ---------------" << endl;

    cout << "--( Operator + )--" << endl;
    cout << a << " + " << b << " = " << a+b << endl;
    cout << b << " + " << c << " = " << b+c << endl;
    cout << c << " + " << d << " = " << c+d << endl;
    cout << d << " + " << e << " = " << d+e << endl << endl;

    cout << "--( Operator - )--" << endl;
    cout << a << " - " << b << " = " << a-b << endl;
    cout << b << " - " << c << " = " << b-c << endl;
    cout << c << " - " << d << " = " << c-d << endl;
    cout << d << " - " << e << " = " << d-e << endl << endl;

    cout << "--( Operator * )--" << endl;
    cout << a << " * " << b << " = " << a*b << endl;
    cout << b << " * " << c << " = " << b*c << endl;
    cout << c << " * " << d << " = " << c*d << endl;
    cout << d << " * " << e << " = " << d*e << endl << endl;

    cout << "--( Operator / )--" << endl;
    cout << a << " / " << b << " = " << a/b << endl;
    cout << b << " / " << c << " = " << b/c << endl;
    cout << c << " / " << d << " = " << c/d << endl;
    cout << d << " / " << e << " = " << d/e << endl << endl;

    // Other
    cout << "  ---------------" << endl;
    cout << "--|     Other    |--" << endl;
    cout << "  ---------------" << endl;
    cout << "--( Change sign )--" << endl;
    cout << a << " -> " << -a << endl;
    cout << b << " -> " << -b << endl;
    cout << c << " -> " << -c << endl;
    cout << d << " -> " << -d << endl << endl;

    cout << "--( Oposite number )--" << endl;
    cout << a << " -> " << !a << endl;
    cout << b << " -> " << !b << endl;
    cout << c << " -> " << !c << endl;
    cout << d << " -> " << !d << endl << endl;

    cout << "--( Cast to double )--" << endl;
    cout << a << " -> " << (double)a << endl;
    cout << b << " -> " << (double)b << endl;
    cout << c << " -> " << (double)c << endl;
    cout << d << " -> " << (double)d << endl << endl;

    Rational test2(51, 100);
    Rational test3(49, 100);
    cout << "--( Cast to int )--" << endl;
    cout << a << " -> " << (int)a << endl;
    cout << b << " -> " << (int)b << endl;
    cout << c << " -> " << (int)c << endl;
    cout << d << " -> " << (int)d << endl;
    cout << test2 << " -> " << (int)test2 << endl;
    cout << test3 << " -> " << (int)test3 << endl << endl;

    {
        cout << "--( Rational output to real number with period )--" << endl;
        Rational r1(4, 9);
        cout << r1 << endl;
        Rational r2(12, 5);
        cout << r2 << endl;
        Rational r3(133, 74);
        cout << r3 << endl;
    }

    // Uncomment to test exception
    // Rational bad(3, 0);
    return 0;
}
