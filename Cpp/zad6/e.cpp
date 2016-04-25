//
// Created by kb on 4/25/16.
//

#include "e.h"
#define _USE_MATH_DEFINES

double E::oblicz() {
    return M_E;
}

std::string E::opis() {
    return std::to_string(oblicz());
}