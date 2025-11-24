#include "Scenes/World.hpp"

Scenes::World::World(SceneHandler &sceneHandler)
    : Scene("Overworld", sceneHandler)
{
}

void Scenes::World::update(bool &runningFlag)
{
}

void Scenes::World::render()
{   
    terminal_clear();
    terminal_print(10, 5, "World Scene");
}
