//
// Created by kb on 4/25/16.
//

#ifndef ZAD6_EXP_H
#define ZAD6_EXP_H
#define _USE_MATH_DEFINES

#include "operator1arg.h"
#include <cmath>

class Exp : public Operator1arg {
public:
    double oblicz();
    Exp(Wyrazenie* w);
    std::string opis();
};

#endif //ZAD6_EXP_H
