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
    sceneHandler.getCurrentScene()->update(_isRunning);
}

void Logic::Game::render()
{
    sceneHandler.getCurrentScene()->render();
}

void Logic::Game::run()
{
    terminal_open();
    terminal_set("window: size=100x50, title='Station 93', cellsize=16x16");
    terminal_set("0xE000: assets/colored_tilemap_packed.png, size=8x8, resize=16x16");

    while (_isRunning)
    {
        render();
        terminal_refresh();
        update();
    }

    terminal_close();
}
