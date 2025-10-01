#include "Options.hpp"
#include "Constants.hpp"
#include "CommandMap.hpp"
#include "Utils.hpp"

#include <fmt/core.h>
#include <fmt/color.h>
#include <iostream>

std::string OPTIONS::P1_username = "P1";
std::string OPTIONS::P2_username = "P2";

int OPTIONS::STEAL_ATTEMPTS = 3;
int OPTIONS::FINISH_NUMBER = 15;

bool OPTIONS::STEAL_MODE = false;

void open_options()
{
    fmt::print
    (
        fmt::fg(fmt::color::cyan),
        "1. First player's username: {}\n"
        "2. Second player's username: {}\n"
        "3. Available steal attempts: {}\n"
        "4. Steal mode: {}\n"
        "5. Finish number: {}\n"
        "6. Exit to main menu.\n\n",
        OPTIONS::P1_username,
        OPTIONS::P2_username,
        OPTIONS::STEAL_ATTEMPTS,
        OPTIONS::STEAL_MODE,
        OPTIONS::FINISH_NUMBER
    );

    std::string option;

    while(true)
    {
        fmt::print(fmt::fg(fmt::color::gold), "Set option: ");

        std::cin >> option;

        if(option == UI::OPTIONS::EXIT)
            return;

        fmt::print(fmt::fg(fmt::color::gold), "Set value: ");

        std::string value;
        std::cin >> value;

        set_option(option, value);

        fmt::print(fmt::fg(fmt::color::lime_green), "The option has been changed successfully to {}\n\n", value);
    }
}

void set_option(std::string option, std::string value)
{
    if(option == UI::OPTIONS::P1_USERNAME)
        OPTIONS::P1_username = value;

    else if(option == UI::OPTIONS::P2_USERNAME)
        OPTIONS::P2_username = value;  

    else if(option == UI::OPTIONS::FINISH_NUMBER)
    {
        if(!is_number(value) || std::stoi(value) <= 0)
            fmt::print(fmt::fg(fmt::color::red), "Value of '{}' might be a positive valid integer.\n\n", option);
        
        else
            OPTIONS::FINISH_NUMBER = std::stoi(value);
    }
        
    else if(option == UI::OPTIONS::STEAL_ATTEMPTS)
    {
        if(!is_number(value) || std::stoi(value) < 0)
            fmt::print(fmt::fg(fmt::color::red), "Value of '{}' must be a positive valid integer.\n\n", option);

        else
            OPTIONS::STEAL_ATTEMPTS = std::stoi(value);
    }
        
    else if(option == UI::OPTIONS::STEAL_MODE)
    {
        if(!is_number(value))
            fmt::print(fmt::fg(fmt::color::red), "Value of '{}' must be a valid integer.\n\n", option);

        else if(std::stoi(value) != true || std::stoi(value) != false)
            fmt::print(fmt::fg(fmt::color::red), "Value of '{}' must be 1 or 0.\n\n", option);

        else
            OPTIONS::STEAL_MODE = std::stoi(value);
    }
        
    else
        fmt::print(fmt::fg(fmt::color::red), "There is no option: '{}'.\n\n", option);
}