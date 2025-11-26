#include "Scenes/SceneHandler.hpp"
#include "Scenes/MainMenu.hpp"
#include "Scenes/World.hpp"
#include "Scenes/Settings.hpp"
#include "Scenes/Help.hpp"

Scenes::SceneHandler::SceneHandler()
{
}

Scenes::SceneHandler::~SceneHandler()
{
}

void Scenes::SceneHandler::changeScene(SceneType newScene)
{
    switch (newScene)
    {
    case SceneType::MainMenu:
        _currentScene = std::make_unique<MainMenu>(*this);
        break;
    case SceneType::Inventory:
        /* code */
        break;
    case SceneType::Settings:
        _currentScene = std::make_unique<Settings>(*this);
        break;
    case SceneType::Map:
        break;
    case SceneType::World:
        _currentScene = std::make_unique<World>(*this);
        break;
    case SceneType::Help:
        _currentScene = std::make_unique<Help>(*this);
        break;

    default:
        break;
    }
}

Scenes::Scene *Scenes::SceneHandler::getCurrentScene()
{
    return _currentScene.get();
}