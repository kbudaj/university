//
// Created by kb on 4/26/16.
//

#include "ln.h"

double Ln::oblicz() {
    return log10(w->oblicz());
}

Ln::Ln(Wyrazenie* w) {
    this->w = w;
}

std::string Ln::opis() {
    return "ln(" + w->opis() + ")";
}