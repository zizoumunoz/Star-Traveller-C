#pragma once
#include <iostream>
#include <array>
#include <string>

namespace GameUI
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
