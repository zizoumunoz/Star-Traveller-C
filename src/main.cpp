#include <iostream>
#include "BearLibTerminal.h"
#include "Scenes\MainMenu.hpp"

int main() 
{
    std::cout << "Star Traveller C";

    Scenes::MainMenu m;

    terminal_open();

    terminal_set("window: size=80x30");
    
    m.render();


    terminal_refresh();
    terminal_read();

    terminal_close();

    // terminal_open();

    // terminal_set("window: size=80x25");
    // terminal_print(2, 1, "Hello, World!");
    // terminal_refresh();
    // terminal_read();
    // terminal_close();

    return 0;
}
