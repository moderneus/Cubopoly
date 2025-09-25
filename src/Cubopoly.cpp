#include "Constants.hpp"
#include "CommandMap.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

#include <iostream>

int main()
{
    srand(time(NULL));

    fmt::print
    (
        fmt::fg(fmt::color::lime_green), 
        "1. Play!\n"
        "2. Settings.\n" //NOT WORKING YET
        "3. Exit.\n\n"
    );

    fmt::print(fmt::fg(fmt::color::gold), "Choice: ");

    int user_input;
    std::cin >> user_input;
    
    auto menu = get_menu_commands();

    while(true)
    {
        auto it = menu.find(user_input);

        if(it != menu.end())
            it->second();

        else
            fmt::print(fmt::fg(fmt::color::red), "There is no command: '{}'\n\n", user_input);
    }

    return EXIT_SUCCESS;
}