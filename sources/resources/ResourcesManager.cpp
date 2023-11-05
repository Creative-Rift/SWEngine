/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: ResourcesManager.cpp
*/

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "resources/ResourcesManager.hpp"

sw::ResourcesManager::ResourcesManager() : Singleton(),
m_textures()
{}

void sw::ResourcesManager::CreateTexture(std::string name, std::string path)
{
    m_textures.createResource(name, std::make_shared<sw::Texture>(path));
}

std::shared_ptr<sw::Texture> sw::ResourcesManager::GetTexture(std::string name)
{
    return m_textures[name];
}