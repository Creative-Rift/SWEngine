/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Component.cpp
*/

#include "components/base/Component.hpp"

sw::Component::Component(sw::GameObject &gameObject, bool isActive) :
m_isActive(isActive),
m_gameObject(gameObject)
{}

std::string sw::Component::gameObjectName() const
{
    return m_gameObject.name();
}

void sw::Component::setActive(bool value)
{
    m_isActive = value;
}

bool sw::Component::isActive() const
{
    return m_isActive;
}

sw::GameObject &sw::Component::gameObject() const
{
    return m_gameObject;
}
