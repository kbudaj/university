//
// Created by kb on 4/25/16.
//

#include "sin.h"

double Sin::oblicz() {
    return sin(w->oblicz());
}

Sin::Sin(Wyrazenie* w) {
    this->w = w;
}

std::string Sin::opis() {
    return "sin(" + w->opis() + ")";
}