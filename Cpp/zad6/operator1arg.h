//
// Created by kb on 4/25/16.
//

#ifndef ZAD6_OPERATOR1ARG_H
#define ZAD6_OPERATOR1ARG_H

#include "operator0arg.h"

class Operator1arg : public Operator0arg {
public:
    Wyrazenie* w;
    std::string opis();
};

#endif //ZAD6_OPERATOR1ARG_H
