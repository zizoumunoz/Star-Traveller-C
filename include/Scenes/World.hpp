#pragma once
#include "Scene.hpp"
#include "Interfaces/IHasUserInput.hpp"
#include "BearLibTerminal.h"

using namespace Interfaces;

namespace Scenes
{
    class World : public Scene, public IHasUserInput
    {
    public:
        World(SceneHandler &sceneHandler);
        ~World() = default;

        // Scene overrides
        void update(bool &runningFlag) override;
        void render();

        // IHasUserInput
        void handleInput() override;

    private:
    };
}
