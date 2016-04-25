//
// Created by kb on 4/26/16.
//

#ifndef ZAD6_OPERATOR2ARG_H
#define ZAD6_OPERATOR2ARG_H

#include "operator1arg.h"

class Operator2arg : public Operator1arg {
public:
    Wyrazenie* w2;
    std::string opis();
};

#endif //ZAD6_OPERATOR2ARG_H
