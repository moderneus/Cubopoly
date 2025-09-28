#pragma once

#include "Player.hpp"

#include <string>

void execute_command(Player& player);

bool is_win(Player& player);

bool is_number(int user_input);

void request_input(std::string& user_input);

void print_start_menu();