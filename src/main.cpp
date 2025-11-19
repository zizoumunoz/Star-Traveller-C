#include <iostream>
#include "BearLibTerminal.h"
#include "Scenes\MainMenu.hpp"
#include "Graphics\AsciiHandler.hpp"
#include <filesystem>

int main()
{
    std::cout << "Star Traveller C\n";
    std::cout << "Working directory: "
              << std::filesystem::current_path() << '\n';

    Scenes::MainMenu mainMenu;

    terminal_open();
    terminal_set("window: size=128x36");

    bool isRunning = true;

    while (isRunning)
    {
        mainMenu.render();

        terminal_refresh();

        if (terminal_read() == TK_ESCAPE)
        {
            isRunning = false;
        }
    }

    terminal_close();

    return 0;
}
