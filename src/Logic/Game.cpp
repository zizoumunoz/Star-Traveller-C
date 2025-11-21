#include "Logic/Game.hpp"

Logic::Game::Game()
{
}

void Logic::Game::changeScene(SceneType newScene)
{
    switch (newScene)
    {
    case Logic::SceneType::MainMenu:
        _currentScene = std::make_unique<Scenes::MainMenu>();
        break;
    case Logic::SceneType::Inventory:
        break;
    case Logic::SceneType::Map:
        break;
    case Logic::SceneType::Settings:
        break;
    case Logic::SceneType::World:
        break;
    default:
        break;
    }
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
