#pragma once
#include <iostream>
#include <array>
#include <string>
#include <utility>
#include "Scene.hpp"
#include "IHasCursor.hpp"
#include "Cursor.hpp"

using namespace Interfaces;

namespace Scenes
{
    enum MenuOption
    {
        StartGame,
        Options,
        Help,
        Exit
    };

    class MainMenu : public Scene, public IHasCursor
    {
    public:
        MainMenu();
        ~MainMenu();

        // Scene
        void update() override;
        void render() override;

        // IHasCursor
        void moveRelative(int x, int y) override;
        void setPosition(int x, int y) override;
        std::pair<int, int> getPosition() override;
        void renderCursor() override;

    private:
        Graphics::Cursor _cursor =
            Graphics::Cursor('>', false, std::make_pair(0, 0));
    };

}
