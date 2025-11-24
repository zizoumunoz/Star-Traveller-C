#pragma once
#include <memory>
#include "Scenes/Scene.hpp"
#include "Scenes/MainMenu.hpp"
#include "Scenes/SceneHandler.hpp"

namespace Logic
{
    class Game
    {
    public:
        Game();

        void changeScene(Scenes::SceneType newScene);
        void update();
        void render();
        void run();

    private:
        bool _isRunning = true;
        Scenes::SceneHandler sceneHandler;
        Scenes::SceneType _currentSceneType = Scenes::SceneType::MainMenu;

        std::unique_ptr<Scenes::Scene> _currentScene =
            std::make_unique<Scenes::MainMenu>(sceneHandler);

    };
}
