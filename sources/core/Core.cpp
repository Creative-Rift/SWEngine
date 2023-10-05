/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Core.cpp
*/

#include <iostream>

#include "core/Core.hpp"
#include "GLFW/glfw3.h"
#include "utils/exception/Error.hpp"

void sw::Core::Start()
{
    std::cout << "Starting Engine..." << std::endl;
    if (!glfwInit())
        throw sw::Error("Glfw cannot be initialize");
    sw::Window::Start();
}

void sw::Core::Stop()
{
    std::cout << "Stopping Engine..." << std::endl;
    glfwTerminate();
}

bool sw::Core::IsRunning()
{
    return sw::Window::IsOpen();
}

void sw::Core::Update()
{
    sw::Window::Update();
}

