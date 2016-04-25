//
// Created by kb on 4/26/16.
//

#include <vector>
#include "wyrazenie.h"

#ifndef ZAD6_ZMIENNA_H
#define ZAD6_ZMIENNA_H

class Zmienna : public Wyrazenie {
    std::vector<std::pair<std::string, double>> zmienne;

public:
    virtual double oblicz();
    virtual std::string opis();
    Zmienna(std::string& z);
    void set(double value);
    void update(double value);
};

#endif //ZAD6_ZMIENNA_H
