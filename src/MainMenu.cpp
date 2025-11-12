#include "MainMenu.hpp"

using namespace GameUI;

MainMenu::MainMenu()
{
    std::cout << "Main Menu created.\n";
}

MainMenu::~MainMenu()
{
}

void GameUI::MainMenu::setMenuOption(MenuOption newOption)
{
    _currentOption = newOption;
}

void GameUI::MainMenu::displayCurrentOption()
{
    std::cout << _MenuOptions[_currentOption];
}