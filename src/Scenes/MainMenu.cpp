#include "Scenes/MainMenu.hpp"

Scenes::MainMenu::MainMenu()
    : Scene("Main Menu")
{
    _titleAscii.loadFromFile("assets\\title_art.txt");
}

Scenes::MainMenu::~MainMenu()
{
}

void Scenes::MainMenu::displayOptions()
{
    for (int i = 0; i < _options.size(); i++)
    {
        terminal_printf(0, 0 + i, "%i. %s", i + 1, _options[i]);
    }
}

void Scenes::MainMenu::update()
{
}

void Scenes::MainMenu::render()
{
    /*
  To do
  2. display menu options
  3. have moving cursor
  4. Read input to exit program
  */
    _titleAscii.displayAscii(10, 2);
    std::cout << _titleAscii.getHeight() << " "
              << _titleAscii.getLength() << "\n";
    displayOptions();
}

void Scenes::MainMenu::cursorMoveRelative(int x, int y)
{
    _cursor._coords.first += x;
    _cursor._coords.second += y;
}

void Scenes::MainMenu::cursorSetPos(int x, int y)
{
    _cursor._coords.first = x;
    _cursor._coords.second = y;
}

std::pair<int, int> Scenes::MainMenu::cursorGetPos()
{
    return _cursor._coords;
}

void Scenes::MainMenu::renderCursor()
{
    terminal_put(_cursor._coords.first,
                 _cursor._coords.second,
                 _cursor._symbol);
}
