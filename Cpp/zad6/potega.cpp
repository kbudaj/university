//
// Created by kb on 4/26/16.
//

#include "potega.h"

double Potega::oblicz() {
    return pow(w->oblicz(), w2->oblicz());
}

Potega::Potega(Wyrazenie* w, Wyrazenie* w2) {
    this->w = w;
    this->w2 = w2;
}

std::string Potega::opis() {
    return "(" + w->opis() + ")^(" + w2->opis() + ")";
}

