#include "Scene.hpp"
#include "Interfaces/IHasUserInput.hpp"

namespace Scenes
{
    class Settings : public Scene, public Interfaces::IHasUserInput
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
