//
// Created by kb on 4/26/16.
//

#include "operator2arg.h"
#include <cmath>

#ifndef ZAD6_LOG_H
#define ZAD6_LOG_H

class Log : public Operator2arg {
public:
    double oblicz();
    Log(Wyrazenie* w, Wyrazenie* w2);
    std::string opis();
};

#endif //ZAD6_LOG_H
