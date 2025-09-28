#pragma once

#include "Player.hpp"

#include <unordered_map>
#include <functional>
#include <string>

using Command = std::function<void(Player&)>;

std::unordered_map<std::string, std::function<void()>> get_menu_commands();

std::unordered_map<std::string, Command> get_play_commands();

std::unordered_map<std::string, std::function<void()>> get_options_commands();