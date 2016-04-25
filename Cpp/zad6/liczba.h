//
// Created by kb on 4/18/16.
//

#ifndef ZAD6_LICZBA_H
#define ZAD6_LICZBA_H

#include "wyrazenie.h"

class Liczba : public Wyrazenie {
    double liczba;
public:
    Liczba(double l);
    virtual double oblicz();
    virtual std::string opis();
    double getValue();
};

#endif //ZAD6_LICZBA_H
