#include "Scenes/Settings.hpp"
#include "Scenes/SceneHandler.hpp"
#include "BearLibTerminal.h"

Scenes::Settings::Settings(SceneHandler &sceneHandler)
    : Scenes::Scene("Settings", sceneHandler)
{
}

void Scenes::Settings::update(bool &runningFlag)
{
    handleInput();
}

void Scenes::Settings::render()
{
    terminal_clear();
    terminal_print(10, 5, "Settings Scene");
}

void Scenes::Settings::handleInput()
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
