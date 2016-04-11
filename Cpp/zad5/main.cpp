#include "wielomian.h"
#include <iostream>

using namespace std;

int main() {
    // Wielomian test(2, 3.3);
    // double wsp[3] = {3.3, 4, 12};
    // Wielomian test(3, wsp);
    {
        cout << "{3, 12, 123, 12.3, 1}" << endl;
        Wielomian test = {3, 12, 123, 12.3, 1};
        cout << test << endl;
        Wielomian test2(test);
        cout << test2 << endl;
        test2[4] = 1337;
        cout << test2[4] << endl;
        test2[4] = 1;
        cout << test2 << endl;
        cout << "------------" << endl;
        Wielomian test3(2, 1.0);
        cout << test3 << endl;
        Wielomian test4; // jednomian z defaultowymi wartosciami
        cout << test4 << endl;
        test4[0] = 0;
        cout << test4 << endl;
    }
    {
        cout << "-- Operacje --" << endl;
        cout << "- Dodawanie";
        Wielomian w1 = {1, -3, 2};
        Wielomian w2 = {-7, 4, 5};
        // cout << w1 << endl;
        // cout << w2 << endl;
        Wielomian w3 = w1 + w2;
        cout << w3 << endl;
    }

    {
        cout << "-- Operacje --" << endl;
        cout << "- += Dodawanie" << endl;
        Wielomian w1 = {5, 0, 10, 6};
        Wielomian w2 = {1, 2, 4};
        w1 += w2;
        cout << w1 << endl;
    }

    // {
    //     cout << "- Odejmowanie";
    //     Wielomian w1 = {5, -4, -4, 7};
    //     Wielomian w2 = {6, 0, 3};
    //     cout << w1 << endl;
    //     cout << w2 << endl;
    //     Wielomian w3 = w1 - w2;
    //     cout << w3 << endl;
    // }

    {
        cout << "---------------" << endl;
        Wielomian w1 = {6, 10, 0, 5};
        Wielomian w2 = {4, 2, 1};
        cout << w1 << endl;
        cout << w2 << endl;
        Wielomian w3 = w1 * w2;
        cout << w3 << endl;
        cout << w3(5) << endl;
    }

    // horner test
    {
        Wielomian w1 = {11, -2, 3, 3};
        cout << w1 << endl;
        cout << w1(3) << endl;
    }

    return 0;
}
