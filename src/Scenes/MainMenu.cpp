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
    renderCursor();
}

void Scenes::MainMenu::moveRelative(int x, int y)
{
    _cursor._coords.first += x;
    _cursor._coords.second += y;
}

void Scenes::MainMenu::setPosition(int x, int y)
{
    _cursor._coords.first = x;
    _cursor._coords.second = y;
}

std::pair<int, int> Scenes::MainMenu::getPosition()
{
    return _cursor._coords;
}

void Scenes::MainMenu::renderCursor()
{
    terminal_put(_cursor._coords.first,
                 _cursor._coords.second,
                 _cursor._symbol);
}
