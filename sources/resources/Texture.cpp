/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Texture.cpp
*/

#include <iostream>

#include "stb_image.h"
#include "glad/glad.h"

#include "resources/Texture.hpp"
#include "utils/exception/Error.hpp"

sw::Texture::Texture(std::string path) :
        m_width(0),
        m_height(0),
        m_channels(0),
        m_data(nullptr),
        m_id(0)
{
    // stbi_set_flip_vertically_on_load(true);
    m_data = stbi_load(path.c_str(), &m_width, &m_height, &m_channels, 0);
    if (!m_data) {
        std::cerr << "Failed to load texture: " << path << std::endl;
        throw sw::Error("Failed to load texture: " + path);
    }
    upload();
}

unsigned int sw::Texture::getId() const
{
    return m_id;
}

int sw::Texture::getWidth() const
{
    return m_width;
}

int sw::Texture::getHeight() const
{
    return m_height;
}

int sw::Texture::getChannels() const
{
    return m_channels;
}

void sw::Texture::upload()
{
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    if (m_data) {
        switch (m_channels) {
            case 1: {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, m_width, m_height, 0, GL_RED, GL_UNSIGNED_BYTE, m_data);
                GLint swizzleMask[] = {GL_RED, GL_RED, GL_RED, GL_ONE};
                glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
            }
                break;
            case 2: {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, m_width, m_height, 0, GL_RG, GL_UNSIGNED_BYTE, m_data);
                GLint swizzleMask[] = {GL_RED, GL_RED, GL_RED, GL_GREEN};
                glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
            }
                break;
            case 3: {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_data);
            }
                break;
            case 4: {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
            }
                break;
            default:
                break;
        }
        stbi_image_free(m_data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to upload texture" << std::endl;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1920, 1080, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
        throw sw::Error("Failed to upload texture");
    }
}
