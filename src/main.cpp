#include <iostream>
#include "BearLibTerminal.h"
#include "MainMenu.hpp"

int main() 
{
    std::cout << "Star Traveller C";

    GameUI::MainMenu mainMenu;

    mainMenu.setMenuOption(GameUI::MenuOption::Options);
    mainMenu.displayCurrentOption();

    terminal_open();

    terminal_set("window: size=100x30");
    terminal_print(2, 1, "Hello, World!");

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
