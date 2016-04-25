//
// Created by kb on 4/25/16.
//

#ifndef ZAD6_GAMMA_H
#define ZAD6_GAMMA_H
#define GAMMA 0.5772156649
// Nie wiem czy dobrze zrozumiałem, ale to ma być Stała Eulera?

#include "operator0arg.h"

class Gamma : public Operator0arg {
public:
    double oblicz();
    std::string opis();
};


#endif //ZAD6_GAMMA_H
