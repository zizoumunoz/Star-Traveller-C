#pragma once
#include <iostream>
#include <array>
#include <string>
#include "Scene.hpp"

namespace Scenes
{
    enum MenuOption
    {
        StartGame,
        Options,
        Help,
        Exit
    };

    class MainMenu : public Scene
    {
    public:
       MainMenu();
       ~MainMenu();

       void update() override;
       void render() override;

    private:
        
    };

}
