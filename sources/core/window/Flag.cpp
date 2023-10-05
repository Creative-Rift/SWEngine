/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Flag.cpp
*/

#include <iostream>

#include "core/window/Window.hpp"

void sw::Window::SetFlag(sw::WindowFlags flags)
{
    if (!HasFlag(sw::WindowFlags::FULLSCREEN_MODE) != (flags & sw::WindowFlags::FULLSCREEN_MODE)) {
        ToggleFullScreen();
    }
    if (!HasFlag(sw::WindowFlags::RESIZABLE) != (flags & sw::WindowFlags::RESIZABLE)) {
        glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, GLFW_TRUE);
        m_flags |= sw::WindowFlags::RESIZABLE;
    }
    if (!HasFlag(sw::WindowFlags::UNDECORATED) != (flags & sw::WindowFlags::UNDECORATED)) {
        glfwSetWindowAttrib(m_window, GLFW_DECORATED, GLFW_FALSE);
        m_flags |= sw::WindowFlags::UNDECORATED;
    }
    if (!HasFlag(sw::WindowFlags::HIDDEN) != (flags & sw::WindowFlags::HIDDEN)) {
        glfwHideWindow(m_window);
        m_flags |= sw::WindowFlags::HIDDEN;
    }
    if (!HasFlag(sw::WindowFlags::MAXIMIZED) != (flags & sw::WindowFlags::MAXIMIZED)) {
        Maximize();
        m_flags |= sw::WindowFlags::MAXIMIZED;
    }
    if (!HasFlag(sw::WindowFlags::MINIMIZED) != (flags & sw::WindowFlags::MINIMIZED)) {
        Minimize();
        m_flags |= sw::WindowFlags::MINIMIZED;
    }
    if (!HasFlag(sw::WindowFlags::UNFOCUSED) != (flags & sw::WindowFlags::UNFOCUSED)) {
        glfwSetWindowAttrib(m_window, GLFW_FOCUS_ON_SHOW, GLFW_FALSE);
        m_flags |= sw::WindowFlags::UNFOCUSED;
    }
    if (!HasFlag(sw::WindowFlags::TRANSPARENT) != (flags & sw::WindowFlags::TRANSPARENT)) {
        std::cout << "Transparency mode must be define before window initialization." << std::endl;
    }
}

void sw::Window::ClearFlag(sw::WindowFlags flags)
{
    if (HasFlag(sw::WindowFlags::FULLSCREEN_MODE) != (flags & sw::WindowFlags::FULLSCREEN_MODE)) {
        ToggleFullScreen();
    }
    if (HasFlag(sw::WindowFlags::RESIZABLE) != (flags & sw::WindowFlags::RESIZABLE)) {
        glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, GLFW_FALSE);
        m_flags &= ~sw::WindowFlags::RESIZABLE;
    }
    if (HasFlag(sw::WindowFlags::UNDECORATED) != (flags & sw::WindowFlags::UNDECORATED)) {
        glfwSetWindowAttrib(m_window, GLFW_DECORATED, GLFW_TRUE);
        m_flags &= ~sw::WindowFlags::UNDECORATED;
    }
    if (HasFlag(sw::WindowFlags::HIDDEN) != (flags & sw::WindowFlags::HIDDEN)) {
        glfwShowWindow(m_window);
        m_flags &= ~sw::WindowFlags::HIDDEN;
    }
    if (HasFlag(sw::WindowFlags::MAXIMIZED) != (flags & sw::WindowFlags::MAXIMIZED)) {
        Restore();
        m_flags &= ~sw::WindowFlags::MAXIMIZED;
    }
    if (HasFlag(sw::WindowFlags::MINIMIZED) != (flags & sw::WindowFlags::MINIMIZED)) {
        Restore();
        m_flags &= ~sw::WindowFlags::MINIMIZED;
    }
    if (HasFlag(sw::WindowFlags::UNFOCUSED) != (flags & sw::WindowFlags::UNFOCUSED)) {
        glfwSetWindowAttrib(m_window, GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
        m_flags &= ~sw::WindowFlags::UNFOCUSED;
    }
    if (HasFlag(sw::WindowFlags::TRANSPARENT) != (flags & sw::WindowFlags::TRANSPARENT)) {
        std::cout << "Transparency mode must be define before window initialization." << std::endl;
    }
}

bool sw::Window::HasFlag(sw::WindowFlags flags)
{
    return (m_flags & flags);
}