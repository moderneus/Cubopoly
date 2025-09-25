#pragma once

#include <sstream>
#include <string>

class Player
{
private:
    std::string _username;
    std::string _input;
    int _score;

public:
    Player(std::string username);

    std::string& get_input();

    int get_score();

    void set_score(int value);

    std::string get_username();

    void set_username(std::string& username);
};