//
// Created by kb on 4/26/16.
//

#include "mnoz.h"

double Mnoz::oblicz() {
    return w->oblicz() * w2->oblicz();
}

Mnoz::Mnoz(Wyrazenie* w, Wyrazenie* w2) {
    this->w = w;
    this->w2 = w2;
}

std::string Mnoz::opis() {
    return "(" + w->opis() + ") * (" + w2->opis() + ")";
}