//
// Created by kb on 4/25/16.
//

#ifndef ZAD6_E_H
#define ZAD6_E_H

#include "operator0arg.h"
#include <cmath>

class E : public Operator0arg {
public:
    double oblicz();
    std::string opis();
};

#endif //ZAD6_E_H
