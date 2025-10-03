#include "Player.hpp"
#include "Constants.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

#include <iostream>

void Player::execute_command(std::unordered_map<std::string, std::function<void()>> commands_map, Player& user)
{
    bool is_executed = false;

    while(!is_executed)
    {
        fmt::print(fmt::fg(fmt::color::gold), "Choice: ");

        std::cin >> user.get_input();

        auto commands = commands_map;
        auto it = commands.find(user.get_input());

        if(it != commands.end())
        {
            it->second();
            is_executed = true;
        }
            
        else
        {
            fmt::print(fmt::fg(fmt::color::red), "There is no command: '{}'\n\n", user.get_input());
        }  
    }
}

void Player::execute_command(std::unordered_map<std::string, std::function<void(Player&)>> commands_map, Player& player)
{
    bool is_executed = false;

    while(!is_executed)
    {
        fmt::print(fmt::fg(fmt::color::gold), "{} player's turn: ", player.get_username());

        std::cin >> player.get_input();
        
        auto commands = commands_map;
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

Player::Player(std::string username)
{
    _username = username;  
    _score = 0;
}

Player::Player()
{
    _username = "";
    _score = 0;
}

std::string& Player::get_input()
{
    return _input;
}

Player* Player::get_enemy()
{
    return _enemy;
}

void Player::set_enemy(Player& enemy)
{
    _enemy = &enemy;
}

int Player::get_score()
{
    return _score;
}

void Player::set_score(int value)
{
    _score = value;
}

std::string Player::get_username()
{
    return _username;
}

void Player::set_username(std::string& svalue)
{
    _username = svalue;
}