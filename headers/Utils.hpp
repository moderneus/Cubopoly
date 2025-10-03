#pragma once

#include <functional>
#include <string>

#include "Player.hpp"

#include <string>

bool is_win(Player& player);

bool is_number(const std::string& user_input);

void request_input(std::string& user_input);

void print_start_menu();