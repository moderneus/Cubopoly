#include "CommandMap.hpp"
#include "Constants.hpp"
#include "Options.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Dice.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

std::unordered_map<std::string, std::function<void()>> get_menu_commands()
{
    return
    {
        {UI::MENU::PLAY, []()
        {
            start_game_loop();
        }},

        {UI::MENU::OPTIONS, []()
        {
            open_options();
        }},

        {UI::MENU::EXIT, []()
        {
            std::exit(EXIT_SUCCESS);
        }}
    };
}

std::unordered_map<std::string, std::function<void(Player&)>> get_play_commands()
{
    Dice dice;

    return
    {
        {GAME::THROW, [&dice](Player& player)
        {   
            int number = dice.roll();

            fmt::print(fmt::fg(fmt::color::lime_green), "The number {} came up!\n", number);
            
            player.set_score(player.get_score() + number);

            fmt::print(fmt::fg(fmt::color::lime_green), "The {} player's score: {}\n\n", player.get_username(), player.get_score());
        }},

        {GAME::SCORE, [](Player& player)
        {
            Player* enemy = player.get_enemy();

            fmt::print(fmt::fg(fmt::color::cyan), "The {}'s score: {}\n", player.get_username(), player.get_score());
            fmt::print(fmt::fg(fmt::color::cyan), "The {}'s score: {}\n\n", enemy->get_username(), enemy->get_score());
        }},

        {GAME::QUIT, [](Player& player)
        {
            fmt::print(fmt::fg(fmt::color::purple), "The {} has been quit.\n\n", player.get_username());

            Player* enemy = player.get_enemy();

            fmt::print(fmt::fg(fmt::color::cyan), "The {}'s score: {}\n", player.get_username(), player.get_score());
            fmt::print(fmt::fg(fmt::color::cyan), "The {}'s score: {}\n\n", enemy->get_username(), enemy->get_score());

            std::exit(EXIT_SUCCESS);
        }},
    };
}