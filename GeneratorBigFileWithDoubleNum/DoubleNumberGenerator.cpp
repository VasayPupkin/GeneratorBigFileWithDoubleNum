#include <random>
#include <iostream>

#include "DoubleNumberGenerator.h"


double DoubleNumberGenerator::generateDoubleNumber()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(MIN_VALUE, MAX_VALUE);
    return dis(gen);
}

