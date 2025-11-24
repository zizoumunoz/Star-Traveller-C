#include "Scenes/SceneHandler.hpp"
#include "Scenes/MainMenu.hpp"
#include "Scenes/World.hpp"

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
        /* code */
        break;
    case SceneType::Map:
        /* code */
        break;
    case SceneType::World:
        _currentScene = std::make_unique<World>(*this);
        break;

    default:
        break;
    }
}

Scenes::Scene *Scenes::SceneHandler::getCurrentScene()
{
    return _currentScene.get();
}