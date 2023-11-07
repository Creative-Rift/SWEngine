/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: GameObject.cpp
*/

#include "boost/uuid/random_generator.hpp"

#include "gameobject/GameObject.hpp"
#include "components/Transform.hpp"

sw::GameObject::GameObject(const std::string name, sw::Scene &scene, bool isActive) :
        m_id(boost::uuids::random_generator()()),
        m_name(name),
        m_isActive(isActive),
        m_scene(scene),
        m_transform(std::make_shared<Transform>(*this))
{}

std::string sw::GameObject::name() const
{
    return m_name;
}

sw::Scene &sw::GameObject::scene()
{
    return m_scene;
}

bool sw::GameObject::isActive() const
{
    return m_isActive;
}

void sw::GameObject::setActive(bool active)
{
    m_isActive = active;
}

boost::uuids::uuid sw::GameObject::id() const
{
    return m_id;
}

sw::Transform &sw::GameObject::transform()
{
    return (*m_transform);
}
