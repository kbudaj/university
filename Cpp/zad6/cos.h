//
// Created by kb on 4/25/16.
//

#ifndef ZAD6_COS_H
#define ZAD6_COS_H

#include "operator1arg.h"
#include <cmath>

class Cos : public Operator1arg {
public:
    double oblicz();
    Cos(Wyrazenie* w);
    std::string opis();
};

#endif //ZAD6_COS_H
