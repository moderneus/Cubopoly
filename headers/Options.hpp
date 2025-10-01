#pragma once

#include <string>
#include <unordered_map>

namespace OPTIONS
{
    extern std::string P1_username;
    extern std::string P2_username;

    extern int STEAL_ATTEMPTS;
    extern int FINISH_NUMBER;

    extern bool STEAL_MODE;
}

void open_options();

void set_option(std::string option, std::string value);