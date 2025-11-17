#include <iostream>
#include "BearLibTerminal.h"
#include "Scenes\MainMenu.hpp"
#include "Graphics\AsciiHandler.hpp"
#include <filesystem>

int main()
{
    std::cout << "Star Traveller C\n";
    std::cout << "Working directory: " << std::filesystem::current_path() << '\n';

    Scenes::MainMenu m;
    Graphics::AsciiHandler ah;

    ah.loadFromFile("assets\\title_art.txt");

    terminal_open();
    terminal_set("window: size=128x36");

    bool isRunning = true;

    while (isRunning)
    {
        m.render();
        ah.displayAscii(2, 2);
        terminal_print(1, 2, "The quick brown fox jumps over the lazy dog");
        terminal_refresh();
        
        if (terminal_read() == TK_ESCAPE)
        {
            isRunning = false;
        }
        
    }

    terminal_close();

    return 0;
}
