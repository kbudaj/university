//
// Created by kb on 4/26/16.
//

#ifndef ZAD6_ODEJMIJ_H
#define ZAD6_ODEJMIJ_H

#include "operator2arg.h"

class Odejmij : public Operator2arg {
public:
    double oblicz();
    Odejmij(Wyrazenie* w, Wyrazenie* w2);
    std::string opis();
};

#endif //ZAD6_ODEJMIJ_H
