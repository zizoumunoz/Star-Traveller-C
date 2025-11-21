#include <iostream>
#include "BearLibTerminal.h"
#include "Scenes/MainMenu.hpp"
#include "Logic/Game.hpp"
#include "Graphics/AsciiHandler.hpp"
#include <filesystem>

int main()
{
    std::cout << "Star Traveller C\n";
    std::cout << "Working directory: "
              << std::filesystem::current_path() << '\n';

    Logic::Game game;

    game.run();

    return 0;
}
