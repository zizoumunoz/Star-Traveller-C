#pragma once
#include "Scene.hpp"
#include "BearLibTerminal.h"

namespace Scenes
{
    class World : public Scene
    {
    public:
        World(SceneHandler& sceneHandler);
        ~World() = default;

        // Scene overrides
        void update(bool &runningFlag) override;
        void render();

    private:
    };
}