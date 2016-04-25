//
// Created by kb on 4/26/16.
//

#include "dodaj.h"

double Dodaj::oblicz() {
    return w->oblicz() + w2->oblicz();
}

Dodaj::Dodaj(Wyrazenie* w, Wyrazenie* w2) {
    this->w = w;
    this->w2 = w2;
}


std::string Dodaj::opis() {
    return "(" + w->opis() + ") + (" + w2->opis() + ")";
}