#include "Scene.hpp"

namespace Scenes
{
    class World : public Scene
    {
    public:
        // Scene overrides
        void update(bool &runningFlag) override;
        void render();

    private:
    };
}