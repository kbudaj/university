//
// Created by kb on 4/18/16.
//

#ifndef ZAD6_WYRAZENIE_H
#define ZAD6_WYRAZENIE_H

#include <string>

class Wyrazenie {
public:
    virtual double oblicz() = 0;
    virtual std::string opis() = 0;
};

#endif //ZAD6_WYRAZENIE_H
