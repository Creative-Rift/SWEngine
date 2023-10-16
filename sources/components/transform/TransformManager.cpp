/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Transform.cpp
*/

#include "components/Transform.hpp"
#include "glm/gtc/matrix_transform.inl"

sw::Transform::Transform(sw::GameObject &gameObject) :
sw::Component(gameObject),
m_matrix(1.0f),
m_position(0, 0, 0),
m_globalPosition(0, 0, 0),
m_scale(1, 1, 1),
m_globalScale(1, 1, 1),
m_angle(0),
m_rotationAxis(0, 1, 0),
m_globalRotationAxis(0, 0, 0)
{}

const glm::mat4 &sw::Transform::getMatrix() noexcept
{
    m_matrix = glm::mat4(1.0f);
    m_matrix = glm::translate(m_matrix, glm::vec3(m_position.x, m_position.y, m_position.z));
    m_matrix = glm::rotate(m_matrix, glm::radians(m_angle), glm::vec3(m_rotationAxis.x, m_rotationAxis.y, m_rotationAxis.z));
    m_matrix = glm::scale(m_matrix, glm::vec3(m_scale.x, m_scale.y, m_scale.z));
    return m_matrix;
}

const glm::mat4 &sw::Transform::getGlobalMatrix()
{
    m_globalMatrix = glm::mat4(1.0f);
    m_globalMatrix = glm::translate(m_globalMatrix, glm::vec3(m_globalPosition.x, m_globalPosition.y, m_globalPosition.z));
    m_globalMatrix = glm::rotate(m_globalMatrix, glm::radians(m_angle), glm::vec3(m_rotationAxis.x, m_rotationAxis.y, m_rotationAxis.z));
    m_globalMatrix = glm::scale(m_globalMatrix, glm::vec3(m_scale.x, m_scale.y, m_scale.z));
    return m_globalMatrix;
}

sw::Vector3f sw::Transform::getTransformPoint(const sw::Vector3f &point)
{
    glm::vec4 resultMatrix = m_matrix * glm::vec4(point.x, point.y, point.z, 1);

    return (sw::Vector3f{resultMatrix.x, resultMatrix.y, resultMatrix.z});
}

sw::Vector3f sw::Transform::getTransformPoint(float x, float y, float z)
{
    glm::vec4 resultMatrix = m_matrix * glm::vec4(x, y, z, 1);

    return (sw::Vector3f{resultMatrix.x, resultMatrix.y, resultMatrix.z});
}

sw::Vector3f sw::Transform::getGlobalTransformPoint(const sw::Vector3f &point)
{
    glm::vec4 resultMatrix = m_globalMatrix * glm::vec4(point.x, point.y, point.z, 1);

    return (sw::Vector3f{resultMatrix.x, resultMatrix.y, resultMatrix.z});
}

sw::Vector3f sw::Transform::getGlobalTransformPoint(float x, float y, float z)
{
    glm::vec4 resultMatrix = m_globalMatrix * glm::vec4(x, y, z, 1);

    return (sw::Vector3f{resultMatrix.x, resultMatrix.y, resultMatrix.z});
}
