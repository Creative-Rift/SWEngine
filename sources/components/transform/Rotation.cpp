/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Rotation.cpp
*/

#include "components/Transform.hpp"

void sw::Transform::setRotation(float angle, float rotationX, float rotationY, float rotationZ)
{
    if (rotationX != 0 || rotationY != 0 || rotationZ != 0 || angle != 0) {
        m_angle = angle;
        m_rotationAxis.x = rotationX;
        m_rotationAxis.y = rotationY;
        m_rotationAxis.z = rotationZ;
        m_globalRotationAxis.x = rotationX;
        m_globalRotationAxis.y = rotationY;
        m_globalRotationAxis.z = rotationZ;

        //for (auto &[_, entity]: m_gameObject.m_childrenMap)
        //    entity.get().transform().setRotation(rotationX, rotationY, rotationZ); TODO: add child system to GameObject
    }
}

void sw::Transform::rotate(float angle, float rotationX, float rotationY, float rotationZ)
{
    if (rotationX != 0 || rotationY != 0 || rotationZ != 0 || angle != 0) {
        m_angle += angle;
        m_rotationAxis.x += rotationX;
        m_rotationAxis.y += rotationY;
        m_rotationAxis.z += rotationZ;
        m_globalRotationAxis.x += rotationX;
        m_globalRotationAxis.y += rotationY;
        m_globalRotationAxis.z += rotationZ;

        //for (auto& [_, entity] : m_gameObject.m_childrenMap)
        //    entity.get().getComponent<sw::Transform>("TransformManager").rotate(rotationX, rotationY, rotationZ); TODO: add child system to GameObject
    }
}

const sw::Vector3f &sw::Transform::getRotationAxis() const noexcept
{
    return m_rotationAxis;
}

const float &sw::Transform::getAngle() const noexcept
{
    return m_angle;
}

const sw::Vector3f &sw::Transform::getGlobalRotationAxis()
{
    return m_globalRotationAxis;
}
