#include "Constants.hpp"
#include "CommandMap.hpp"
#include "Utils.hpp"

#include <fmt/core.h>
#include <fmt/color.h>

#include <iostream>

int main()
{
    srand(time(NULL));

    while(true)
    {
        print_start_menu();

        std::string user_input;

        request_input(user_input);

        auto menu = get_menu_commands();

        auto it = menu.find(user_input);

        if(it != menu.end())
            it->second();

        else
            fmt::print(fmt::fg(fmt::color::red), "There is no choice: '{}'\n\n", user_input);
    }

    return EXIT_SUCCESS;
}