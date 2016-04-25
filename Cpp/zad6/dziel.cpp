//
// Created by kb on 4/26/16.
//

#include "dziel.h"

double Dziel::oblicz() {
    return w->oblicz() / w2->oblicz();
}

Dziel::Dziel(Wyrazenie* w, Wyrazenie* w2) {
    this->w = w;
    this->w2 = w2;
    assert(w2->oblicz() != 0);
}

std::string Dziel::opis() {
    return "(" + w->opis() + ") / (" + w2->opis() + ")";
}