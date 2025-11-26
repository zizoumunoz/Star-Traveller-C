#pragma once
#include <memory>
#include "Scene.hpp"

namespace Scenes
{

    enum class SceneType
    {
        MainMenu,
        Inventory,
        Settings,
        Help,
        Map,
        World
    };

    class SceneHandler
    {
    public:
        SceneHandler();
        ~SceneHandler();

        void changeScene(SceneType newScene);
        Scene *getCurrentScene();

    private:
        std::unique_ptr<Scene> _currentScene;
    };
}
