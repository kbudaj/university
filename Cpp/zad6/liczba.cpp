//
// Created by kb on 4/18/16.
//

#include <iostream>
#include "liczba.h"

Liczba::Liczba(double l) {
    this->liczba = l;
}

double Liczba::oblicz() {
    std::cout << "Wynik liczby: " << std::endl;
}

std::string Liczba::opis() {
    std::cout << "Opis liczby: " << std::endl;
}







