/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Core.cpp
*/

#include <iostream>

#include "core/Core.hpp"
#include "GLFW/glfw3.h"
#include "utils/exception/Error.hpp"

SW_MODULE_EXPORT sw::SceneManager sw::Core::m_sceneManager{};

void sw::Core::Start()
{
    std::cout << "Starting Engine..." << std::endl;
    if (!glfwInit())
        throw sw::Error("Glfw cannot be initialize");
    m_sceneManager.loadScene(m_sceneManager.getSceneByIndex(0)->getName());
    sw::Window::Start();
}

void sw::Core::Stop()
{
    std::cout << "Stopping Engine..." << std::endl;
    m_sceneManager.unloadAllScene();
    glfwTerminate();
}

bool sw::Core::IsRunning()
{
    return sw::Window::IsOpen();
}

void sw::Core::Update()
{
    m_sceneManager.checkForNewScene();

    sw::Window::Update();
}

sw::SceneManager &sw::Core::GetSceneManager() {
    return m_sceneManager;
}

