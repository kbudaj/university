#include "wielomian.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void Wielomian::set(int index, double val) {
    if (index == 0) {
        throw invalid_argument("Can't set zero.");
    }
    this->a[index] = val;
}

Wielomian::proxy& Wielomian::proxy::operator=(double val) {
    parent.set(index, val);
    return *this;
}

Wielomian::proxy::operator double() {
    return parent.a.at(index);
}

Wielomian::proxy::proxy(Wielomian& p, size_t index) : parent(p), index(index) {}

Wielomian::Wielomian(int st, double wsp) {
    this->n = st;
    this->a.push_back(wsp);
}

Wielomian::Wielomian(int st, double wsp[]) {
    this->n = st;
    int wsp_size = st+1; // Wielomian stopnia n, moze miec max n+1 wyrazow
    for (int i=0; i<wsp_size; i++) {
       this->a.push_back(wsp[i]);
    }
}

Wielomian::Wielomian(initializer_list<double> wsp) {
    // Skoro wielomian stopnia n, ma max n-1 wyrazow
    // to rozmiar initializer_list odpowiada wielomianowi
    // stopnia n-1.
    this->n = wsp.size() - 1;

    for (auto element : wsp){
        this->a.push_back(element);
    }
}

Wielomian::proxy Wielomian::operator[](int i) {
    if (i > this->n+1) {
        throw out_of_range("So such index."); 
    } 
    return Wielomian::proxy(*this, i);
}

ostream& operator<<(ostream& wy, const Wielomian& w) {
    // Wyraz n, wg specyfikacji, przyjmuje wspolczynnik o indeksie n
    // Wypisywanie od tylu
    int stopien = w.n;
    
    for (int i=w.a.size() - 1; i>=0; i--, stopien--) {
        if (i != w.a.size() - 1) {
            wy << " + ";
        } 
        if (i > 1) {
            wy << "(" << w.a.at(i) << ")" << "x^" << stopien;
        } else if (i == 1) {
            wy << "(" << w.a.at(i) << ")" << "x";
        } else {
            wy << w.a.at(i);
        }
    }

    return wy;

}
