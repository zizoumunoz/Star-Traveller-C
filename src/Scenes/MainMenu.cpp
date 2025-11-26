#include "Scenes/MainMenu.hpp"

Scenes::MainMenu::MainMenu(SceneHandler &sceneHandler)
    : Scene("Main Menu", sceneHandler)
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
        terminal_printf(_titleLeftPadding, 5 + _titleAscii.getHeight() + i,
                        "%i. %s", i + 1, _options[i]);
    }
}

void Scenes::MainMenu::update(bool &runningFlag)
{
    terminal_set("window: size=128x36, title='Station 93 - Main Menu'");
    while (terminal_has_input())
    {
        int key = terminal_read();

        switch (key)
        {
        case TK_UP:
        case TK_W:
        {
            cursorMoveConstrained(0, -1, _optionsXConstraints, _optionsYConstraints);
            break;
        }
        case TK_DOWN:
        case TK_S:
        {
            cursorMoveConstrained(0, 1, _optionsXConstraints, _optionsYConstraints);
            break;
        }
        case TK_ENTER:
        {
            switch (_cursor._coords.second)
            {
            case MenuOption::StartGame:
            {
                std::cout << "Start Game, setting scene to world:\n";
                _sceneHandler.changeScene(Scenes::SceneType::World);

                break;
            }
            case MenuOption::Options:
            {
                std::cout << "Settings\n";
                _sceneHandler.changeScene(Scenes::SceneType::Settings);
                break;
            }
            case MenuOption::UserHelp:
            {
                std::cout << "Help\n";
                _sceneHandler.changeScene(Scenes::SceneType::Help);
                break;
            }
            case MenuOption::Exit:
            {
                std::cout << "Exit\n";
                runningFlag = false;
                break;
            }

            default:
                break;
            }
            break;
        }

        case TK_ESCAPE:
            runningFlag = false;
            break;
        default:
            break;
        }
    }
}

void Scenes::MainMenu::render()
{
    /*
  To do
  2. display menu options
  3. have moving cursor
  4. Read input to exit program
  */
    terminal_clear();
    _titleAscii.displayAscii(10, 2);
    displayOptions();
    renderCursor();
    terminal_printf(0, 0,
                    "%i, %i", _cursor._coords.first, _cursor._coords.second);
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

void Scenes::MainMenu::cursorMoveConstrained(int x, int y,
                                             std::pair<int, int> xConstrain,
                                             std::pair<int, int> yConstrain)
{
    if (_cursor._coords.second + y >= yConstrain.first &&
        _cursor._coords.second + y <= yConstrain.second)
    {
        cursorMoveRelative(x, y);
    }
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
