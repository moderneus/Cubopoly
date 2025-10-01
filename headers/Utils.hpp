#pragma once

#include <functional>
#include <string>

#include "Player.hpp"

#include <string>

void execute_command(std::unordered_map<std::string, std::function<void()>> commands_map, Player& user);

void execute_command(std::unordered_map<std::string, std::function<void(Player&)>> commands_map, Player& user);

bool is_win(Player& player);

bool is_number(const std::string& user_input);

void request_input(std::string& user_input);

void print_start_menu();