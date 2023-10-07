/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: SceneManager.cpp
*/

#include <iostream>

#include "scene/sceneManager/SceneManager.hpp"

sw::SceneManager::SceneManager() noexcept :
m_scenes(),
m_activeScene(),
m_nextActiveScene()
{}

std::shared_ptr<sw::Scene> sw::SceneManager::createScene(std::string name)
{
    if (m_scenes.contains(name))
        std::cout << "Scene [" << name << "] already exist!";
    else
        return m_scenes.try_emplace(name, std::make_shared<sw::Scene>(name)).first->second;
    return m_scenes.at(name);
}

std::shared_ptr<sw::Scene> sw::SceneManager::createScene(sw::Scene *scene)
{
    if (m_scenes.contains(scene->getName()))
        std::cout << "Scene [" << scene->getName() << "] already exist!";
    else
        return m_scenes.try_emplace(scene->getName(), scene).first->second;
    return m_scenes.at(scene->getName());
}

void sw::SceneManager::loadScene(std::string sceneName)
{
    if (!m_scenes.contains(sceneName)) {
        std::cout << "Scene [" << sceneName << "] dosen't exist" << std::endl;
        return;
    }
    m_nextActiveScene = sceneName;
}

void sw::SceneManager::unloadAllScene()
{
    for (auto& [_, scene] : m_scenes)
        scene->unload();
    m_scenes.clear();
    m_activeScene.clear();
    m_nextActiveScene.clear();
}

void sw::SceneManager::checkForNewScene()
{
    if (m_nextActiveScene.empty())
        return;
    if (!m_activeScene.empty())
        getActiveScene()->unload();
    m_activeScene = m_nextActiveScene;
    m_nextActiveScene.clear();
    m_scenes.at(m_activeScene)->load();
}

std::shared_ptr<sw::Scene> sw::SceneManager::getSceneByName(std::string sceneName)
{
    return m_scenes.at(sceneName);
}

std::shared_ptr<sw::Scene> sw::SceneManager::getSceneByIndex(unsigned int index)
{
    auto it = m_scenes.begin();

    if (index > m_scenes.size())
        throw std::out_of_range("Index is out of range");
    for (int i = 0; i < index; i++)
        it++;
    return it->second;
}

std::shared_ptr<sw::Scene> sw::SceneManager::getActiveScene()
{
    return getSceneByName(m_activeScene);
}


