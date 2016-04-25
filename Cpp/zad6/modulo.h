//
// Created by kb on 4/26/16.
//

#ifndef ZAD6_MODULO_H
#define ZAD6_MODULO_H

#include "operator2arg.h"
#include <cmath>
#include "assert.h"

class Modulo : public Operator2arg {
public:
    double oblicz();
    Modulo(Wyrazenie* w, Wyrazenie* w2);
    std::string opis();
};

#endif //ZAD6_MODULO_H
