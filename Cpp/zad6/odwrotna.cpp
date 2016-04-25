//
// Created by kb on 4/25/16.
//

#include "odwrotna.h"

double Odwrotna::oblicz() {
    return pow(w->oblicz(), -1);
}

Odwrotna::Odwrotna(Wyrazenie* w) {
    this->w = w;
    assert(w->oblicz() != 0);
}

std::string  Odwrotna::opis() {
    return "(" + w->opis() + ")^-1";
}