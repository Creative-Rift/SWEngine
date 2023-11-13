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
SW_MODULE_EXPORT sw::Chronos sw::Core::m_chronos(sw::Chronos::Wait);
SW_MODULE_EXPORT sw::Chronos sw::Core::m_chronosWindow(sw::Chronos::Wait);
SW_MODULE_EXPORT double sw::Core::m_frameRate{1.0/60.0};

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
    m_chronos.start();
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

    if (m_frameRate != 0.0) {
        auto sleep = std::chrono::milliseconds(static_cast<int>((m_frameRate - m_chronosWindow.getTotalTime()) * 1000));
        if (sleep.count() > 0)
            std::this_thread::sleep_for(sleep);
        m_chronosWindow.stop();
        m_chronosWindow.start();
    }
    m_chronos.tour();
}

sw::SceneManager &sw::Core::GetSceneManager() {
    return m_sceneManager;
}

sw::ResourcesManager &sw::Core::GetResourceManager()
{
    return m_resourceManager;
}

void sw::Core::setFrameRateLimit(unsigned int frameRate)
{
    m_frameRate = 1.0 / static_cast<double>(frameRate);
}

