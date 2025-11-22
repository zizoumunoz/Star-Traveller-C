#pragma once
#include <string>
#include "BearLibTerminal.h"
namespace Scenes
{
    class Scene
    {
    public:
        Scene(std::string name);
        virtual ~Scene();

        virtual void update(bool &runningFlag) = 0;
        virtual void render() = 0;

    protected:
        std::string _name;

    private:
    };
}
