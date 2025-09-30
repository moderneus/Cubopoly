#pragma once

#include <sstream>
#include <string>

class Player
{
private:
    std::string _username;
    std::string _input;
    Player* _enemy;
    int _score;

public:
    Player(std::string username);

    std::string& get_input();

    Player* get_enemy();

    void set_enemy(Player& enemy);

    void set_score(int value);

    int get_score();

    void set_username(std::string& username);

    std::string get_username();
};