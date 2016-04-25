//
// Created by kb on 4/26/16.
//

#include "odejmij.h"

double Odejmij::oblicz() {
    return w->oblicz() - w2->oblicz();
}

Odejmij::Odejmij(Wyrazenie* w, Wyrazenie* w2) {
    this->w = w;
    this->w2 = w2;
}

std::string Odejmij::opis() {
    return "(" + w->opis() + ") - (" + w2->opis() + ")";
}