//
// Created by kb on 4/25/16.
//

#include "pi.h"

double Pi::oblicz() {
    return M_PI;
}

std::string Pi::opis() {
    return std::to_string(oblicz());
}