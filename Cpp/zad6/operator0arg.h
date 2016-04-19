//
// Created by kb on 4/18/16.
//

#include "wyrazenie.h"
#include <string>
#include <vector>
#include <utility>

#ifndef ZAD6_OPERATOR0ARG_H
#define ZAD6_OPERATOR0ARG_H

class Operator0arg : public Wyrazenie {
    std::vector<std::pair<std::string, double>> args = {
            {"pi", 3.14},
    };

public:
    Operator0arg(std::string arg);
};

#endif //ZAD6_OPERATOR0ARG_H
