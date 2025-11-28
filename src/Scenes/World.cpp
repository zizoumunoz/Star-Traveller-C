#include "Scenes/World.hpp"
#include "Scenes/SceneHandler.hpp"
#include "Scenes/MainMenu.hpp"

Scenes::World::World(SceneHandler &sceneHandler)
    : Scene("Overworld", sceneHandler)
{
}

void Scenes::World::displayMapViewport()
{
    const int height = 100;
    const int width = 30;
    const int initialX = 4;
    const int initialY = 2;

    for (size_t y = initialY; y < width; y++)
    {
        for (size_t x = initialX; x < height; x++)
        {
            terminal_put(x, y, 0xE045);
        }
    }
}

void Scenes::World::update(bool &runningFlag)
{
    terminal_set("window: size=100x50, title='Station 93 - World'");
    handleInput();
}

void Scenes::World::render()
{
    terminal_clear();
    displayMapViewport();
    terminal_print(10, 5, "World Scene");
}

void Scenes::World::handleInput()
{
    while (terminal_has_input())
    {
        int input = terminal_read();
        switch (input)
        {
        case TK_ESCAPE:
            _sceneHandler.changeScene(Scenes::SceneType::MainMenu);
            break;

        default:
            break;
        }
    }
}
