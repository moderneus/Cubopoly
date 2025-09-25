#include "Player.hpp"

Player::Player(std::string username)
{
    _username = username;
}

std::string& Player::get_input()
{
    return _input;
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
