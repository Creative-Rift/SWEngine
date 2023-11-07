/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Scene.cpp
*/

#include <iostream>

#include "boost/uuid/uuid_hash.hpp"

#include "scene/Scene.hpp"
#include "utils/exception/Error.hpp"
#include "gameobject/GameObject.hpp"
#include "managers/TransformManager.hpp"
#include "managers/SpriteManager.hpp"

sw::Scene::Scene(const std::string name) :
m_name(name),
m_isLoad(false)
{
    std::cout << "Scene object created with name: " << name << std::endl;
}

void sw::Scene::load()
{
    if (m_isLoad)
        return;

    std::cout << "Loading Scene(" << m_name << ")..." << std::endl;

    createManager<sw::TransformManager>();
    createManager<sw::SpriteManager>();

    for (auto& [_, manager] : m_managers)
        manager->load();

    m_isLoad = true;
}

void sw::Scene::update()
{
    if (!m_isLoad)
        return;

    updatePhysic();
    updateLogic();

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    updateGraphics();
}

void sw::Scene::unload()
{
    if (!m_isLoad)
        return;
    std::cout << "Unloading Scene(" << m_name << ")..." << std::endl;

    for (auto& [_, manager] : m_managers)
        manager->unload();
    m_managers.clear();
    m_gameObjects.clear();
    m_deleteGameObject.clear();
    m_isLoad = false;
}

bool sw::Scene::isLoad() const
{
    return m_isLoad;
}

void sw::Scene::updatePhysic()
{

}

void sw::Scene::updateLogic()
{

}

void sw::Scene::updateGraphics()
{
    getManager<sw::SpriteManager>(typeid(sw::SpriteManager).name()).onUpdate();
}

const std::string &sw::Scene::getName() const
{
    return m_name;
}

sw::GameObject &sw::Scene::createGameObject(const std::string &gameObjectName)
{
    auto newGameObject = std::make_shared<sw::GameObject>(gameObjectName, *this);

    return dynamic_cast<sw::GameObject&>(*m_gameObjects.try_emplace(newGameObject->id(), newGameObject).first->second);
}

sw::GameObject &sw::Scene::getGameObjectByName(const std::string &gameObjectName)
{
    for (auto& [_, gameObject] : m_gameObjects) {
        if (gameObject->name() == gameObjectName)
            return *gameObject;
    }
    throw sw::Error("GameObject not found");
}

sw::GameObject &sw::Scene::getGameObjectById(const boost::uuids::uuid gameObjectId)
{
    if (m_gameObjects.contains(gameObjectId))
        return *m_gameObjects[gameObjectId];
    throw sw::Error("GameObject not found");
}

bool sw::Scene::hasGameObject(const std::string &gameObjectName)
{
    for (auto& [_, gameObject] : m_gameObjects) {
        if (gameObject->name() == gameObjectName)
            return true;
    }
    return false;
}

bool sw::Scene::hasGameObject(const boost::uuids::uuid gameObjectId)
{
    return m_gameObjects.contains(gameObjectId);
}

void sw::Scene::deleteGameObject(const std::string &gameObjectName)
{
    m_deleteGameObject.emplace(getGameObjectByName(gameObjectName).id());
}

void sw::Scene::deleteGameObject(const boost::uuids::uuid gameObjectId)
{
    m_deleteGameObject.emplace(gameObjectId);
}

void sw::Scene::eraseGameObject()
{
    for (auto& [id, _] : m_gameObjects)
        deleteGameObject(id);
}

void sw::Scene::deleteRequestedGameObject()
{
    for (auto& id : m_deleteGameObject) {
        m_gameObjects.erase(id);
    }
    m_deleteGameObject.clear();
}