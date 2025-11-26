#pragma once
#include "Scene.hpp"
#include "Interfaces/IHasUserInput.hpp"

using namespace Interfaces;

namespace Scenes
{
    class Help : public Scene, public IHasUserInput
    {
    public:
        Help(SceneHandler &sceneHandler);
        ~Help() = default;

        // Scene overrides
        void update(bool &runningFlag) override;
        void render() override;

        // IHasUserInput overrides
        void handleInput() override;

    private:
    };
}
