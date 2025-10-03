#include "Game.hpp"
#include "CommandMap.hpp"
#include "Options.hpp"
#include "Player.hpp"
#include "Utils.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

void start_game_loop()
{
    Player p1(OPTIONS::P1_username);
    Player p2(OPTIONS::P2_username);

    p1.set_enemy(p2);
    p2.set_enemy(p1);

    fmt::print(fmt::fg(fmt::color::hot_pink), "The game is on! The finish number is {}\n\n", OPTIONS::FINISH_NUMBER);

    while(true)
    {
        p1.execute_command(get_play_commands(), p1);

        if(is_win(p1))
            return;
        
        p2.execute_command(get_play_commands(), p2);

        if(is_win(p2))
            return;
    }
}