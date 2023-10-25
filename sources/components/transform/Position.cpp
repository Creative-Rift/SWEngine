/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Position.cpp
*/

#include "components/Transform.hpp"

void sw::Transform::setPosition(const sw::Vector3f &position)
{
    move(position - m_position);
}

void sw::Transform::setPosition(const sw::Vector2f &position)
{
    move({m_position.x - position.x, m_position.y - position.y});
}

void sw::Transform::setPosition(float x, float y, float z)
{
    move({x - m_position.x, y - m_position.y, z - m_position.z});
}

void sw::Transform::move(const sw::Vector3f &position)
{
    if (position.x != 0 || position.y != 0 || position.z != 0) {
        m_position += position;
        m_globalPosition += position;
        //for (auto &[_, gameObject]: m_gameObject.m_childrenMap) TODO add child system to GameObject
        //    gameObject.get().transform().move(position);
    }
}

void sw::Transform::move(const sw::Vector2f &position)
{
    move({position.x, position.y, 0});
}

void sw::Transform::move(float x, float y, float z)
{
    move({x, y, z});
}

const sw::Vector3f &sw::Transform::getPosition() const noexcept
{
    return m_position;
}

const sw::Vector3f &sw::Transform::getGlobalPosition() const noexcept
{
    return m_globalPosition;
}
