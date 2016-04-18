//
// Created by kb on 4/18/16.
//

#ifndef ZAD6_WYRAZENIE_H
#define ZAD6_WYRAZENIE_H

#include <string>;

class Wyrazenie {
    virtual ~Wyrazenie();

    virtual double oblicz();

    virtual string opis();
};

#endif //ZAD6_WYRAZENIE_H
