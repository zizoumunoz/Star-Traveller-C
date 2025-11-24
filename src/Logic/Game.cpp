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
    _currentScene->update(_isRunning);
}

void Logic::Game::render()
{
    _currentScene->render();
}

void Logic::Game::run()
{
    terminal_open();
    terminal_set("window: size=128x36");

    while (_isRunning)
    {

        terminal_refresh();
    }

    terminal_close();
}
