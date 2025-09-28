#include "Game.hpp"
#include "CommandMap.hpp"
#include "Player.hpp"
#include "Utils.hpp"
#include "Constants.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

#include <string>
#include <iostream>

void start_game_loop()
{
    Player p1("P1");
    Player p2("P2");

    fmt::print(fmt::fg(fmt::color::purple), "The game is on! The finish number is {}\n\n", GAME::FINISH_NUMBER);

    while(true)
    {
        execute_command(p1);

        if(is_win(p1))
            return;
        
        execute_command(p2);

        if(is_win(p2))
            return;
    }
}