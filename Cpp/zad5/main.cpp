#include "wielomian.h"
#include "main.h"
#include <iostream>

using namespace std;


void dodawanie() {
        cout << "  ---- Dodawanie ----  " << endl;

        Wielomian w1;
        Wielomian w2;
        Wielomian wynik;

        cout << " --------------------- " << endl;
        cout << "| Pierwszy Wielomian  |" << endl;
        cout << " --------------------- " << endl;

        cin >> w1;

        cout << "-> " << w1 << endl;
        cout << " --------------------- " << endl;
        cout << "|   Drugi Wielomian   |" << endl;
        cout << " --------------------- " << endl;

        cin >> w2;

        cout << "-> " << w2 << endl;
        cout << " --------------------- " << endl;
        cout << "|         WYNIK       |" << endl;
        cout << " --------------------- " << endl;

        wynik = w1 + w2;

        cout << "-> " << wynik << endl;
        cout << " ------------------------- " << endl;
        cout << "| wielomian1 += wielomian2|" << endl;
        cout << " ------------------------- " << endl;
        cout << "|       wielomian1:       |" << endl;
        cout << " ------------------------- " << endl;

        w1 += w2;
        cout << "-> " << w1 << endl;
    }

void odejmowanie() {
        cout << "  --- Odejmowanie ---  " << endl;

        Wielomian w1;
        Wielomian w2;
        Wielomian wynik;

        cout << " --------------------- " << endl;
        cout << "| Pierwszy Wielomian  |" << endl;
        cout << " --------------------- " << endl;

        cin >> w1;

        cout << "-> " << w1 << endl;
        cout << " --------------------- " << endl;
        cout << "|   Drugi Wielomian   |" << endl;
        cout << " --------------------- " << endl;

        cin >> w2;

        cout << "-> " << w2 << endl;
        cout << " --------------------- " << endl;
        cout << "|         WYNIK       |" << endl;
        cout << " --------------------- " << endl;

        wynik = w1 - w2;

        cout << "-> " << wynik << endl;
        cout << " ------------------------- " << endl;
        cout << "| wielomian1 -= wielomian2|" << endl;
        cout << " ------------------------- " << endl;
        cout << "|       wielomian1:       |" << endl;
        cout << " ------------------------- " << endl;

        w1 -= w2;
        cout << "-> " << w1 << endl;
}


void mnozenie() {
        cout << "  ---- Mnozenie -----  " << endl;

        Wielomian w1;
        Wielomian w2;
        Wielomian wynik;

        cout << " --------------------- " << endl;
        cout << "| Pierwszy Wielomian  |" << endl;
        cout << " --------------------- " << endl;

        cin >> w1;

        cout << "-> " << w1 << endl;
        cout << " --------------------- " << endl;
        cout << "|   Drugi Wielomian   |" << endl;
        cout << " --------------------- " << endl;

        cin >> w2;

        cout << "-> " << w2 << endl;
        cout << " --------------------- " << endl;
        cout << "|         WYNIK       |" << endl;
        cout << " --------------------- " << endl;

        wynik = w1 * w2;

        cout << "-> " << wynik << endl;
        cout << " ------------------------- " << endl;
        cout << "| wielomian1 *= wielomian2|" << endl;
        cout << " ------------------------- " << endl;
        cout << "|       wielomian1:       |" << endl;
        cout << " ------------------------- " << endl;

        w1 -= w2;
        cout << "-> " << w1 << endl;
}

void horner() {
        cout << "  ------ Horner -----   " << endl;

        Wielomian w;
        Wielomian wynik;
        int pkt;

        cout << " --------------------- " << endl;
        cout << "|      Wielomian      |" << endl;
        cout << " --------------------- " << endl;

        cin >> w;

        cout << "-> " << w << endl;
        cout << " --------------------- " << endl;
        cout << "|        Punkt        |" << endl;
        cout << " --------------------- " << endl;

        cout << "Punkt: ";
        cin >> pkt;
        while (cin.fail()) {
            cerr << "Punkt musi byc liczba: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> pkt;
        }

        cout << "-> " << pkt << endl;
        cout << " --------------------- " << endl;
        cout << "|         WYNIK       |" << endl;
        cout << " --------------------- " << endl;

        wynik = w(pkt);

        cout << "-> " << wynik << endl;
}

int main() {
    cout << "Wybierz operacje do testowania: " << endl;
    cout << "\t 1: Dodawanie" << endl;
    cout << "\t 2: Odejmowanie" << endl;
    cout << "\t 3: Mnozenie" << endl;
    cout << "\t 4: Horner" << endl;
    cout << "\t 0: Wyjscie" << endl;
    cout << "(1/2/3/4/q): ";
    int choice;
    cin >> choice;
    while (cin.fail() || choice < 0 || choice > 4 ) {
        cerr << "Wybierz liczbe 0-4: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> choice;
    }

    switch(choice) {
        case 1:
            dodawanie();
            break;
        case 2:
            odejmowanie();
            break;
        case 3:
            mnozenie();
            break;
        case 4:
            horner();
            break;
        case 0:
            break;
    }

    return 0;
}
