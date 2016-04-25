//
// Created by kb on 4/25/16.
//

#ifndef ZAD6_ODWROTNA_H
#define ZAD6_ODWROTNA_H

#include "operator1arg.h"
#include <assert.h>
#include <cmath>

class Odwrotna : public Operator1arg {
public:
    double oblicz();
    Odwrotna(Wyrazenie* w);
    std::string opis();
};

#endif //ZAD6_ODWROTNA_H
