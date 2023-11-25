/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: ScriptManager.cpp
*/

#include "managers/ScriptManager.hpp"

void sw::ScriptManager::load()
{
    sw::AManager<sw::Script>::load();
    for (auto& [id, component] : m_components)
        component->onStart();
}

void sw::ScriptManager::onUpdate()
{
    for (auto& [id, component] : m_components)
        component->onUpdate();
}