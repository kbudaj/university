//
// Created by kb on 4/26/16.
//

#include "operator2arg.h"
#include "assert.h"

#ifndef ZAD6_DZIEL_H
#define ZAD6_DZIEL_H

class Dziel : public Operator2arg {
public:
    double oblicz();
    Dziel(Wyrazenie* w, Wyrazenie* w2);
    std::string opis();
};

#endif //ZAD6_DZIEL_H
