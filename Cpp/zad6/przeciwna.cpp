//
// Created by kb on 4/25/16.
//

#include "przeciwna.h"

double Przeciwna::oblicz() {
    return w->oblicz() * (-1);
}

Przeciwna::Przeciwna(Wyrazenie* w) {
    this->w = w;
}

std::string Przeciwna::opis() {
    return "-(" + w->opis() + ")";
}





