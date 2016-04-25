//
// Created by kb on 4/26/16.
//

#ifndef ZAD6_POTEGA_H
#define ZAD6_POTEGA_H

#include "operator2arg.h"
#include <cmath>

class Potega : public Operator2arg {
public:
    double oblicz();
    Potega(Wyrazenie* w, Wyrazenie* w2);
    std::string opis();
};

#endif //ZAD6_POTEGA_H
