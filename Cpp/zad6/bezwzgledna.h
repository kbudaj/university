//
// Created by kb on 4/25/16.
//

#ifndef ZAD6_BEZWZGLEDNA_H
#define ZAD6_BEZWZGLEDNA_H

#include "operator1arg.h"
#include <cmath>

class Bezwzgledna : public Operator1arg {
public:
    double oblicz();
    Bezwzgledna(Wyrazenie* w);
    std::string opis();
};

#endif //ZAD6_BEZWZGLEDNA_H
