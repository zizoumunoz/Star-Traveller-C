#pragma once
#include <iostream>
#include <array>
#include <string>

namespace Scenes
{
    enum MenuOption
    {
        StartGame,
        Options,
        Help,
        Exit
    };

    class MainMenu
    {
    public:
        MainMenu();
        ~MainMenu();

        void setMenuOption(MenuOption x);
        void displayMenu();
        void displayCurrentOption();

    private:
        std::array<std::string, 4> _MenuOptions = {
            "Start Game",
            "Options",
            "Help",
            "Exit",
        };

        MenuOption _currentOption;
    };

}
