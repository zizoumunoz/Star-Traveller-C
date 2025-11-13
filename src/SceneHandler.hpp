#pragma once

namespace GameUI
{
    enum class SceneType
    {
        MainMenu,
        Settings,
        Game
    };

    class SceneHandler
    {
    public:
        SceneHandler();
        ~SceneHandler();

        void changeScene(SceneType newScene);

    private:
        SceneType _currentScene = SceneType::MainMenu;
    };

}