#include <iostream>
#include "wyrazenie.h"
#include "liczba.h"

using namespace std;

int main() {
    Wyrazenie w;
    w.oblicz();
    Liczba l(2);
    l.oblicz();
    cout << "Tests" << endl;
    return 0;
}