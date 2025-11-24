#include "Logic/Game.hpp"

Logic::Game::Game()
{
    sceneHandler.changeScene(Scenes::SceneType::MainMenu);
}

void Logic::Game::changeScene(Scenes::SceneType newScene)
{
    switch (newScene)
    {
    case Scenes::SceneType::MainMenu:
        break;
    case Scenes::SceneType::Inventory:
        break;
    case Scenes::SceneType::Map:
        break;
    case Scenes::SceneType::Settings:
        break;
    case Scenes::SceneType::World:
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
