//
// Created by kb on 4/26/16.
//

#include "log.h"

double Log::oblicz() {
    return log(w->oblicz()) / log(w2->oblicz());
}

Log::Log(Wyrazenie* w, Wyrazenie* w2) {
    this->w = w;
    this->w2 = w2;
}

std::string Log::opis() {
    return "log(" + w->opis() + ", " + w2->opis() + ")";
}