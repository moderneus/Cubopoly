#include "Utils.hpp"
#include "Options.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

#include <string>
#include <sstream>

bool is_win(Player& player)
{
    if(player.get_score() >= OPTIONS::FINISH_NUMBER)
    {
        fmt::print(fmt::fg(fmt::color::purple), "The {} wins!!!\n\n\a", player.get_username());

        return true;
    }
    
    else
    {
        return false;
    }
}

bool is_number(const std::string& str)
{
    std::istringstream ss(str);

    int x;
    if(!(ss >> x))
        return false;

    char c;
    if(ss >> c)
        return false;

    return true;
}

void print_start_menu()
{
    fmt::print
    (
        fmt::fg(fmt::color::white_smoke), 
        "1. Play!\n"
        "2. Options.\n"
        "3. Exit.\n\n"
    );
}