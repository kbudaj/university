#include "wielomian.h"
#include <iostream>

using namespace std;

int main() {
    // Wielomian test(2, 3.3);
    // double wsp[3] = {3.3, 4, 12};
    // Wielomian test(3, wsp);
    cout << "{3, 12, 123, 12.3, 1}" << endl;
    Wielomian test = {3, 12, 123, 12.3, 1};
    cout << test << endl;
    Wielomian test2(test);
    cout << test2[4] << endl;
    test2[2] = 1212;
    cout << test2[2] << endl;
    return 0;
}
