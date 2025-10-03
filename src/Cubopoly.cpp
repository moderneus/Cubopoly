#include "CommandMap.hpp"
#include "Utils.hpp"

int main()
{
    Player user;
    
    while(true)
    {
        print_start_menu();

        user.execute_command(get_menu_commands(), user);
    }
}