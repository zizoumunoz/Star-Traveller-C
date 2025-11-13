#include "MainMenu.hpp"

using namespace Scenes;

MainMenu::MainMenu()
{
    std::cout << "Main Menu created.\n";
}

MainMenu::~MainMenu()
{
}

void Scenes::MainMenu::setMenuOption(MenuOption newOption)
{
    _currentOption = newOption;
}

void Scenes::MainMenu::displayCurrentOption()
{
    std::cout << _MenuOptions[_currentOption];
}

void Scenes::MainMenu::displayMenu()
{
    
    
}