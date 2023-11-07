/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Core.cpp
*/

#include <iostream>

#include "glad/glad.h"

#include "core/Core.hpp"
#include "GLFW/glfw3.h"
#include "utils/exception/Error.hpp"

SW_MODULE_EXPORT sw::SceneManager sw::Core::m_sceneManager{};
SW_MODULE_EXPORT sw::ResourcesManager sw::Core::m_resourceManager{};

void sw::Core::Start()
{
    std::cout << "Starting Engine..." << std::endl;
    if (!glfwInit())
        throw sw::Error("Glfw cannot be initialize");
    m_sceneManager.loadScene(m_sceneManager.getSceneByIndex(0)->getName());
    sw::Window::Start();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw sw::Error("Failed to initialize GLAD");

    glViewport(0, 0, 1920, 1080);
    glEnable(GL_DEPTH_TEST);
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

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_sceneManager.getActiveScene()->update();
    sw::Window::Update();
}

sw::SceneManager &sw::Core::GetSceneManager() {
    return m_sceneManager;
}

sw::ResourcesManager &sw::Core::GetResourceManager()
{
    return m_resourceManager;
}

