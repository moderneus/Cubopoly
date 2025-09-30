#include "Utils.hpp"
#include "CommandMap.hpp"
#include "Constants.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

#include <string>
#include <sstream>
#include <iostream>

void execute_command(Player& player)
{
    bool is_executed = false;

    while(!is_executed)
    {
        auto commands = get_play_commands();

        fmt::print(fmt::fg(fmt::color::gold), "{} player's turn: ", player.get_username());

        std::cin >> player.get_input();
        
        auto it = commands.find(player.get_input());

        if(it != commands.end())
        {
            it->second(player);

            if(player.get_input() == GAME::THROW)
                is_executed = true;
        }
            
        else
        {
            fmt::print(fmt::fg(fmt::color::red), "There is no command: '{}'\n\n", player.get_input());
        }  
    }
}

bool is_win(Player& player)
{
    if(player.get_score() >= GAME::FINISH_NUMBER)
    {
        fmt::print(fmt::fg(fmt::color::purple), "The {} wins!!!\n\n\a", player.get_username());

        return true;
    }
    
    else
    {
        return false;
    }
}

bool is_number(std::string& user_input)
{
    std::istringstream ss(user_input);

    int x;
    if(!(ss >> x))
        return false;

    char c;
    if(ss >> c)
        return false;

    return true;
}

void request_input(std::string& user_input)
{
    while(!is_number(user_input))
    {
        fmt::print(fmt::fg(fmt::color::gold), "Choice: ");

        std::cin >> user_input;

        if(!is_number(user_input))
            fmt::print(fmt::fg(fmt::color::red), "Enter the number, please.\n\n");
    }
}


void print_start_menu()
{
    fmt::print
    (
        fmt::fg(fmt::color::white_smoke), 
        "1. Play!\n"
        "2. Settings.\n" //NOT WORKING YET
        "3. Exit.\n\n"
    );
}