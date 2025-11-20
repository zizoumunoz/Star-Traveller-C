#include "Logic/Game.hpp"

Logic::Game::Game()
{
}

void Logic::Game::update()
{
}

void Logic::Game::render()
{
}

void Logic::Game::run()
{
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
}
