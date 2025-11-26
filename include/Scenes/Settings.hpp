#pragma once
#include "Interfaces/IHasUserInput.hpp"
#include "Scene.hpp"

using namespace Interfaces;

namespace Scenes
{
    class Settings : public Scene, public IHasUserInput
    {
    public:
        Settings(SceneHandler &sceneHandler);
        ~Settings() = default;

        // Scene overrides
        void update(bool &runningFlag) override;
        void render() override;

        // IHasUserInput overrides
        void handleInput() override;

    private:
    };
}
