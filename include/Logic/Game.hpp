#pragma once

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
        void changeScene(SceneType newScene);
        void update();
        void render();

    private:
        SceneType _currentScene = SceneType::MainMenu;
    };
}