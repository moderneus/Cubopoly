#pragma once

#include <sstream>
#include <string>

#include <unordered_map>
#include <functional>

class Player
{
private:
    std::string _username;
    std::string _input;
    Player* _enemy;
    int _score;

public:
    void execute_command(std::unordered_map<std::string, std::function<void(Player&)>> commands_map, Player& player);

    void execute_command(std::unordered_map<std::string, std::function<void()>> commands_map, Player& user);

    Player(std::string username);

    Player();

    std::string& get_input();

    Player* get_enemy();

    void set_enemy(Player& enemy);

    void set_score(int value);

    int get_score();

    void set_username(std::string& username);

    std::string get_username();
};