#include "Dice.hpp"

#include <random>

int Dice::roll()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> u(1, 6);

    return u(gen);
}