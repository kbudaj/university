//
// Created by kb on 4/26/16.
//

#ifndef ZAD6_DODAJ_H
#define ZAD6_DODAJ_H

#include "wyrazenie.h"
#include "operator2arg.h"

class Dodaj : public Operator2arg {
public:
    virtual double oblicz();
    Dodaj(Wyrazenie* w, Wyrazenie* w2);
    virtual std::string opis();
};

#endif //ZAD6_DODAJ_H
