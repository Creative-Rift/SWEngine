/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Scale.cpp
*/

#include "components/Transform.hpp"

void sw::Transform::setScale(const sw::Vector3f &scaleVec)
{
    scale(scaleVec / m_scale);
}

void sw::Transform::setScale(const sw::Vector2f &scaleVec)
{
    scale({scaleVec.x / m_scale.x, scaleVec.y / m_scale.y, 1.0f});
}

void sw::Transform::setScale(float x, float y, float z)
{
    scale({x / m_scale.x, y / m_scale.y, z / m_scale.z});
}

void sw::Transform::scale(const sw::Vector3f &scale)
{
    if (scale.x != 0 || scale.y != 0 || scale.z != 0) {
        m_scale *= scale;
        m_globalScale *= scale;
        //for (auto& [_, gameObject] : m_gameObject.m_childrenMap) TODO: add child system to GameObject
        //    gameObject.get().transform().scale(scale);
    }
}

void sw::Transform::scale(const sw::Vector2f &scaleVec)
{
    scale({scaleVec.x, scaleVec.y, 1});
}

void sw::Transform::scale(const float x, const float y, const float z)
{
    scale({x, y, z});
}

const sw::Vector3f &sw::Transform::getScale() const noexcept
{
    return m_scale;
}

const sw::Vector3f &sw::Transform::getGlobalScale() const noexcept
{
    return m_globalScale;
}