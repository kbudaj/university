#include "wielomian.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void Wielomian::set(int index, double val) {
    if (index == static_cast<int>(this->a.size())-1 && val == 0 && this->n != 0) {
        cout << "size: " << this->a.size() << endl;
        cout << "i: " << index << endl;
        throw invalid_argument("Can't set zero.");
    }
    this->a[index] = val;
}

double Wielomian::get(int index) const {
    return this->a[index];
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
    // Skoro wielomian stopnia n, ma max n+1 wyrazow
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
    auto a_size = static_cast<int>(w.a.size());

    for (int i=a_size - 1; i>=0; i--, stopien--) {
        if (i != a_size - 1) {
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

istream& operator>>(istream& we, Wielomian& w) {
    // Przyklad
    // -3 2 9 12   =  (12)x^3 + (9)x^2 + (2)x + -3
    int new_n;
    double new_wsp;
    cout << "Stopien wielomianu: ";
    we >> new_n;

    while (we.fail() || new_n < 0) {
        cerr << "Stopien wielomianu musi byc liczba naturalna: ";
        we.clear();
        we.ignore(256,'\n');
        we >> new_n;
    }
    w.n = new_n;

    int i = 0;
    while (i<w.n) {
        cout << "Wspolczynnik " << i << " : ";
        we >> new_wsp;
        while (we.fail()) {
            cerr << "Wspolczynnik musi byc liczba: ";
            we.clear();
            we.ignore(256,'\n');
            we >> new_wsp;
        }
        w.a.push_back(new_wsp);
        i++;
    }

    cout << "Wspolczynnik " << i << " : ";
    we >> new_wsp;
    while (we.fail() || new_wsp == 0) {
        cerr << "Stopien wielomianu przy najwyzszej " << endl;
        cerr << "potedze, musi byc liczba != 0" << endl;
        cerr << "Wspolczynnik " << i << " : ";
        we.clear();
        we.ignore(256,'\n');
        we >> new_wsp;
    }
    w.a.push_back(new_wsp);

    return we;
}

// Operacje
Wielomian operator+(const Wielomian& w1, const Wielomian& w2) {
    int new_n; // Stopien nowego wielomianu
    int smaller_size;
    const Wielomian* bigger;

    if (w1.n > w2.n) {
        new_n = w1.n;
        smaller_size = static_cast<int>(w2.a.size());
        bigger = &w1;
    } else {
        new_n = w2.n;
        smaller_size = static_cast<int>(w1.a.size());
        bigger = &w2;
    }

    double new_wsp[new_n+1]; // Tablica nowych wspolczynnikow

    int i = 0;
    while (i<smaller_size) {
        new_wsp[i] = w1.get(i) + w2.get(i);
        i++;
    }

    while (i<new_n+1) {
        new_wsp[i] = bigger->get(i);
        i++;
    }

    return Wielomian(new_n, new_wsp);
}

Wielomian operator-(const Wielomian& w1, const Wielomian& w2) {
    int new_n; // Stopien nowego wielomianu
    int smaller_size;
    const Wielomian* bigger;

    if (w1.n > w2.n) {
        new_n = w1.n;
        smaller_size = static_cast<int>(w2.a.size());
        bigger = &w1;
    } else {
        new_n = w2.n;
        smaller_size = static_cast<int>(w1.a.size());
        bigger = &w2;
    }

    double new_wsp[new_n+1]; // Tablica nowych wspolczynnikow

    int i = 0;
    while (i<smaller_size) {
        new_wsp[i] = w1.get(i) - w2.get(i);
        i++;
    }

    while (i<new_n+1) {
        new_wsp[i] = bigger->get(i);
        i++;
    }

    return Wielomian(new_n, new_wsp);
}

Wielomian operator*(const Wielomian& w1, const Wielomian& w2) {
    int new_n = w1.n + w2.n; // Stopien nowego wielomianu

    double new_wsp[new_n+1]; // Tablica nowych wspolczynnikow

    for (int i=0; i<new_n+1; i++) {
        new_wsp[i] = 0;
    }

    for (int i=0; i<w1.n+1; i++) {
        for (int j=0; j<w2.n+1; j++) {
            new_wsp[i+j] += w1.get(i)*w2.get(j);
        }
    }
    return Wielomian(new_n, new_wsp);
}

Wielomian& Wielomian::operator+=(const Wielomian& w) {
    *this = *this + w;
    return *this;
}

Wielomian& Wielomian::operator-=(const Wielomian& w) {
    *this = *this - w;
    return *this;
}

Wielomian& Wielomian::operator*=(const Wielomian& w) {
    *this = *this * w;
    return *this;
}

double Wielomian::operator()(int pkt){
    // Horner
    double result = this->get(this->n);
    for (int i=this->n-1; i>=0; i--) {
        result = result*pkt + this->get(i);
    }
    return result;
}
