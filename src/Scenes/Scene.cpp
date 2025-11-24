#include "Scenes/Scene.hpp"

Scenes::Scene::Scene(std::string name, SceneHandler &sceneHandler)
    : _name(name), _sceneHandler(sceneHandler)
{
}

Scenes::Scene::~Scene()
{
}
