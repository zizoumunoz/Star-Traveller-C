#pragma once
#include <string>
#include "BearLibTerminal.h"
namespace Scenes
{
    // Forward dec
    class SceneHandler;

    class Scene
    {
    public:
        Scene(std::string name, SceneHandler &sceneHandler);
        virtual ~Scene();

        virtual void update(bool &runningFlag) = 0;
        virtual void render() = 0;

    protected:
        std::string _name;
        SceneHandler &_sceneHandler;

    private:
    };
}
