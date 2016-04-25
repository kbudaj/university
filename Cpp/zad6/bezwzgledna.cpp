//
// Created by kb on 4/25/16.
//

#include "bezwzgledna.h"

double Bezwzgledna::oblicz() {
    return fabs(w->oblicz());
}

Bezwzgledna::Bezwzgledna(Wyrazenie* w) {
    this->w = w;
}

std::string Bezwzgledna::opis() {
    return "|" + std::to_string(w->oblicz()) + "|";
}