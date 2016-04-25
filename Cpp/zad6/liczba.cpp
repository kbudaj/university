//
// Created by kb on 4/18/16.
//

#include <iostream>
#include "liczba.h"

Liczba::Liczba(double l) : liczba(l) {}

double Liczba::oblicz() {
    return this->liczba;
}

std::string Liczba::opis() {
    std::cout << "Opis liczby: " << std::endl;
}

double Liczba::getValue() {
    return this->liczba;
}








