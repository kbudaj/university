//
// Created by kb on 4/25/16.
//

#ifndef ZAD6_PRZECIWNA_H
#define ZAD6_PRZECIWNA_H

#include "operator1arg.h"
#include <cmath>

class Przeciwna : public Operator1arg {
public:
    double oblicz();
    Przeciwna(Wyrazenie* w);
    std::string opis();
};

#endif //ZAD6_PRZECIWNA_H
