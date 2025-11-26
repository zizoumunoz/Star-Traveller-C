#include "Scenes/World.hpp"
#include "Scenes/SceneHandler.hpp"
#include "Scenes/MainMenu.hpp"

Scenes::World::World(SceneHandler &sceneHandler)
    : Scene("Overworld", sceneHandler)
{
}

void Scenes::World::update(bool &runningFlag)
{
    terminal_set("window: size=128x36, title='Station 93 - World'");
    handleInput();
}

void Scenes::World::render()
{
    terminal_clear();
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
