#include "MainMenu.hpp"

Scenes::MainMenu::MainMenu()
    : Scene("Main Menu")
{
}

Scenes::MainMenu::~MainMenu()
{
}

void Scenes::MainMenu::update()
{
}

void Scenes::MainMenu::render()
{
    terminal_print(1, 2, "Main Menu Scene");
}
