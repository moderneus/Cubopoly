#include "Utils.hpp"
#include "CommandMap.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

void execute_command(Player& player)
{
    bool is_executed = false;

    while(!is_executed)
    {
        auto commands = get_play_commands();

        auto it = commands.find(player.get_input());

        if(it != commands.end())
        {
            it->second(player);

            is_executed = true;
        }
            
        else
        {
            fmt::print(fmt::fg(fmt::color::red), "There is no command: '{}'\n\n", player.get_input());
        }  
    }
}

bool check_win(Player& player, int finish_number)
{
    if(player.get_score() == finish_number)
    {
        fmt::print(fmt::fg(fmt::color::lime_green), "The {} wins!!!\n\n", player.get_username());

        return true;
    }
    
    else
    {
        return false;
    }

    return false;
}