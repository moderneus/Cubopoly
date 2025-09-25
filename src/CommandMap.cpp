#include "CommandMap.hpp"
#include "Constants.hpp"
#include "Player.hpp"
#include "Game.hpp"

#include <stdlib.h>
#include <ctime>

#include <fmt/core.h>
#include <fmt/color.h>

std::unordered_map<int, std::function<void()>> get_menu_commands()
{
    return
    {
        {UI::MENU::PLAY, []()
        {
            start_game_loop(GAME::FINISH_NUMBER);
        }},

        {UI::MENU::EXIT, []()
        {
            std::exit(EXIT_SUCCESS);
        }}
    };
}

std::unordered_map<std::string, std::function<void(Player&)>> get_play_commands()
{
    return
    {
        {GAME::THROW, [](Player& player)
        {   
            int number = (rand() % 6) + 1;

            fmt::print(fmt::fg(fmt::color::lime_green), "The number {} came up!", number);

            player.set_score(player.get_score() + number);
        }},

        {GAME::SCORE, [](Player& player)
        {
            fmt::print(fmt::fg(fmt::color::purple), "The {} player's score: {}\n", player.get_username());
        }},

        // {GAME::QUIT, []()
        // {
            
        // }},
    };
}