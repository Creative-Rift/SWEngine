/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: VertexArray.cpp
*/

#include "glad/glad.h"

#include "utils/VertexArray.hpp"

sw::VertexArray::VertexArray() :
m_vbo{0},
m_vao{0},
m_ebo{0},
m_array{},
m_indices{0, 1, 3, 1, 2, 3}
{
    sw::Vector3f a{0.5f, 0.5f, 0.0f};
    sw::Vector3f b{0.5f, -0.5f, 0.0f};
    sw::Vector3f c{-0.5f, -0.5f, 0.0f};
    sw::Vector3f d{-0.5f, 0.5f, 0.0f};
    m_array.emplace_back(a, sw::WhiteColor);
    m_array.emplace_back(b, sw::WhiteColor);
    m_array.emplace_back(c, sw::WhiteColor);
    m_array.emplace_back(d, sw::WhiteColor);
}

sw::VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
}

void sw::VertexArray::update()
{
    if (m_vao == 0) {
        glGenVertexArrays(1, &m_vao);
        glGenBuffers(1, &m_vbo);
        glGenBuffers(1, &m_ebo);
    }

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(sw::Vertex) * m_array.size(), m_array.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW);

    // Vertex position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    glEnableVertexAttribArray(0);

    // Vertex Color
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    // Vertex TextureCoord
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoord));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

const unsigned int& sw::VertexArray::getVAO() const noexcept
{
    return (m_vao);
}

const unsigned int& sw::VertexArray::getEBO() const noexcept
{
    return (m_ebo);
}

sw::Vertex &sw::VertexArray::operator[](std::size_t index)
{
    return (m_array.at(index));
}