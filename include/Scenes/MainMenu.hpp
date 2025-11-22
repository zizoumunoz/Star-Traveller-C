#pragma once
#include <iostream>
#include <array>
#include <string>
#include <utility>
#include "Scene.hpp"
#include "Interfaces/IHasCursor.hpp"
#include "Graphics/Cursor.hpp"
#include "Graphics/AsciiHandler.hpp"
#include "BearLibTerminal.h"

using namespace Interfaces;

namespace Scenes
{
    enum MenuOption
    {
        StartGame = 14,
        Options,
        Help,
        Exit
    };

    class MainMenu : public Scene, public IHasCursor
    {
    public:
        MainMenu();
        ~MainMenu();

        void displayOptions();

        // Scene
        void update(bool &runningFlag) override;
        void render() override;

        // IHasCursor
        void cursorMoveRelative(int x, int y) override;
        void cursorSetPos(int x, int y) override;
        void cursorMoveConstrained(int x, int y,
                                   std::pair<int, int> xConstrain,
                                   std::pair<int, int> yConstrain) override;
        std::pair<int, int> cursorGetPos() override;
        void renderCursor() override;

    private:
        // Handling of cursor moving is messy, will fix later
        Graphics::Cursor _cursor =
            Graphics::Cursor('>', false, std::make_pair(9 - 1, 14));
        Graphics::AsciiHandler _titleAscii;
        std::array<std::string, 4> _options = {
            "Start Game", "Settings", "Help", "Exit"};
        int _titleLeftPadding = 10;
        int _titleTopPadding = 2;
        int _optionsX = 5;
        std::pair<int, int> _optionsXConstraints = std::make_pair(0, 0);
        std::pair<int, int> _optionsYConstraints = std::make_pair(14, 17);
    };
}
