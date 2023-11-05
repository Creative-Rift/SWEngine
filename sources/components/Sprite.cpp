/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Sprite.cpp
*/

#include "components/Sprite.hpp"
#include "resources/ResourcesManager.hpp"

sw::Sprite::Sprite(sw::GameObject& gameObject) :
sw::Component(gameObject),
m_vertexArray{},
// m_material(),
m_color(),
m_rect(),
m_invertedX(false),
m_invertedY(false)
{
    m_rect = {0.0f, 0.0f, 100, 100};
}

std::shared_ptr<sw::Shader> sw::Sprite::getShader() const noexcept
{
    return (m_shader);
}

// sw::Material &sw::Sprite::getMaterial() noexcept
// {
//     return (m_material);
// }

sw::Sprite &sw::Sprite::setTexture(std::string& name)
{
    auto texture = static_cast<sw::ResourcesManager *>(sw::ResourcesManager::GetInstance())->GetTexture(name);
    // m_material.setTexture(name);
    m_texture = texture;
    m_rect = {0.0f, 0.0f, (float)texture->getWidth(), (float)texture->getHeight()};
    return (*this);
}

sw::Sprite &sw::Sprite::setTextureRect(sw::FloatRect &rect)
{
    m_rect = rect;
    return (*this);
}

sw::Sprite &sw::Sprite::setColor(const sw::Color &color)
{
    m_color = color;
    m_vertexArray[1].color = m_color;
    m_vertexArray[0].color = m_color;
    m_vertexArray[3].color = m_color;
    m_vertexArray[2].color = m_color;
    return (*this);
}

sw::Sprite& sw::Sprite::flipOnX(bool invert)
{
    m_invertedX = invert;
    return (*this);
}

sw::Sprite& sw::Sprite::flipOnY(bool invert)
{
    m_invertedY = invert;
    return (*this);
}

bool sw::Sprite::isFlippedX() const
{
    return (m_invertedX);
}

bool sw::Sprite::isFlippedY() const
{
    return (m_invertedY);
}

std::shared_ptr<sw::Texture> sw::Sprite::texture() const
{
    return (m_texture);
}
