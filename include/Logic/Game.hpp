#pragma once
#include <memory>
#include "Scenes/Scene.hpp"
#include "Scenes/MainMenu.hpp"

namespace Logic
{

    enum class SceneType
    {
        MainMenu,
        Inventory,
        Settings,
        Map
    };

    class Game
    {
    public:
        Game();

        void changeScene(SceneType newScene);
        void update();
        void render();
        void run();

    private:
        SceneType _currentSceneType = SceneType::MainMenu;
        std::unique_ptr<Scenes::Scene> _currentScene =
            std::make_unique<Scenes::MainMenu>();
    };
}