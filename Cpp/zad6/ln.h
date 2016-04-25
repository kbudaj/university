//
// Created by kb on 4/26/16.
//

#ifndef ZAD6_LN_H
#define ZAD6_LN_H

#include "operator1arg.h"
#include <cmath>

class Ln : public Operator1arg {
public:
    double oblicz();
    Ln(Wyrazenie* w);
    std::string opis();
};

#endif //ZAD6_LN_H
