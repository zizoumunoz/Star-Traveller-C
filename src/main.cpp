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
    
    terminal_set("window: size=80x30");
    
    m.render();
    ah.displayAscii(2, 2);

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
