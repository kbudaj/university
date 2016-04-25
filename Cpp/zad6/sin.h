//
// Created by kb on 4/25/16.
//

#ifndef ZAD6_SIN_H
#define ZAD6_SIN_H

#include "operator1arg.h"
#include <cmath>

class Sin : public Operator1arg {
public:
    double oblicz();
    Sin(Wyrazenie* w);
    std::string opis();
};


#endif //ZAD6_SIN_H
