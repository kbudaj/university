//
// Created by kb on 4/26/16.
//

#include "modulo.h"

double Modulo::oblicz() {
    return fmod(w->oblicz(), w2->oblicz());
}

Modulo::Modulo(Wyrazenie* w, Wyrazenie* w2) {
    this->w = w;
    this->w2 = w2;
    assert(w2->oblicz() != 0);
}

std::string Modulo::opis() {
    return "(" + w->opis() + ") % (" + w2->opis() + ")";
}