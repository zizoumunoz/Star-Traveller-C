#include "Scenes/Help.hpp"
#include "Scenes/SceneHandler.hpp"
#include "BearLibTerminal.h"

Scenes::Help::Help(SceneHandler &sceneHandler)
    : Scene("Help", sceneHandler)
{
}

void Scenes::Help::update(bool &runningFlag)
{
    terminal_set("window: size=100x50, title='Station 93 - Help'");
    handleInput();
}

void Scenes::Help::render()
{
    terminal_clear();
    terminal_print(10, 5, "User Help Scene");
}

void Scenes::Help::handleInput()
{
    while (terminal_has_input())
    {
        int key = terminal_read();
        switch (key)
        {
        case TK_ESCAPE:
            _sceneHandler.changeScene(Scenes::SceneType::MainMenu);
            break;

        default:
            break;
        }
    }
}
