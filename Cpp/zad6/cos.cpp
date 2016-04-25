//
// Created by kb on 4/25/16.
//

#include "cos.h"

double Cos::oblicz() {
    return cos(w->oblicz());
}

Cos::Cos(Wyrazenie* w) {
    this->w = w;
}

std::string Cos::opis() {
    return "cos(" + w->opis() + ")";
}