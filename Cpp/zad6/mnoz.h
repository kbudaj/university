//
// Created by kb on 4/26/16.
//

#ifndef ZAD6_MNOZ_H
#define ZAD6_MNOZ_H

#include "operator2arg.h"

class Mnoz : public Operator2arg {
    double oblicz();
    Mnoz(Wyrazenie* w, Wyrazenie* w2);
    std::string opis();
};

#endif //ZAD6_MNOZ_H
