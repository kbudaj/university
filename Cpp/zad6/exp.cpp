//
// Created by kb on 4/25/16.
//

#include "exp.h"

double Exp::oblicz() {
    return exp(w->oblicz());
}

Exp::Exp(Wyrazenie* w) {
    this->w = w;
}

std::string Exp::opis() {
    return "exp(" + w->opis() + ")";
}