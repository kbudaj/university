//
// Created by kb on 4/25/16.
//

#ifndef ZAD6_PI_H
#define ZAD6_PI_H
#define _USE_MATH_DEFINES

#include "operator0arg.h"
#include <cmath>

class Pi : public Operator0arg {
public:
    double oblicz();
    std::string opis();
};

#endif //ZAD6_PI_H
