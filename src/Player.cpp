#include "Player.hpp"

Player::Player(std::string username)
{
    _username = username;  
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
