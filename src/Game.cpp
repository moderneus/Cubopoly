#include "Game.hpp"
#include "CommandMap.hpp"
#include "Player.hpp"
#include "Utils.hpp"
#include "Constants.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

#include <string>
#include <iostream>

void start_game_loop(int finish_number)
{
    bool is_won = false;

    Player p1("P1");
    Player p2("P2");

    while(is_won = false)
    {
        fmt::print(fmt::fg(fmt::color::purple), "The game is on! The finish number is {}\n\n", finish_number);

        fmt::print(fmt::fg(fmt::color::gold), "First player's turn: ");

        std::cin >> p1.get_input();

        execute_command(p1);

        is_won = check_win(p1, GAME::FINISH_NUMBER);
            
        fmt::print(fmt::fg(fmt::color::gold), "Second player's turn: ");

        std::cin >> p2.get_input();

        execute_command(p2);

        is_won = check_win(p1, GAME::FINISH_NUMBER);

        fmt::print(fmt::fg(fmt::color::gold), "Second player's turn: ");
    }
}