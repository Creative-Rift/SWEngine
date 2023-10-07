/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Scene.cpp
*/

#include <iostream>

#include "scene/Scene.hpp"

sw::Scene::Scene(const std::string name) :
m_name(name),
m_isLoad(false)
{
    std::cout << "Scene object created with name: " << name << std::endl;
}

void sw::Scene::load()
{
    if (m_isLoad)
        return;

    std::cout << "Loading Scene(" << m_name << ")..." << std::endl;
    m_isLoad = true;
}

void sw::Scene::update()
{
    if (!m_isLoad)
        return;

    updatePhysic();
    updateLogic();
    updateGraphics();
}

void sw::Scene::unload()
{
    if (!m_isLoad)
        return;
    std::cout << "Unloading Scene(" << m_name << ")..." << std::endl;

    m_isLoad = false;
}

bool sw::Scene::isLoad() const
{
    return m_isLoad;
}

void sw::Scene::updatePhysic()
{

}

void sw::Scene::updateLogic()
{

}

void sw::Scene::updateGraphics()
{

}

const std::string &sw::Scene::getName() const
{
    return m_name;
}
