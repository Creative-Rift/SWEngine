/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Window.cpp
*/

#include <iostream>

#include "core/window/Window.hpp"
#include "utils/exception/Error.hpp"
#include "core/monitor/Monitor.hpp"

SW_MODULE_EXPORT GLFWwindow*    sw::Window::m_window(nullptr);
SW_MODULE_EXPORT bool           sw::Window::m_fullScreen(false);
SW_MODULE_EXPORT sw::Vector2i   sw::Window::m_size({1920, 1080});
SW_MODULE_EXPORT sw::Vector2i   sw::Window::m_maxSize{1920, 1080};
SW_MODULE_EXPORT sw::Vector2i   sw::Window::m_position{0, 0};
SW_MODULE_EXPORT std::string    sw::Window::m_title("ShipWreck Engine");
SW_MODULE_EXPORT unsigned int   sw::Window::m_flags(0);
SW_MODULE_EXPORT bool           sw::Window::m_cursorHidden(false);
SW_MODULE_EXPORT bool           sw::Window::m_ready(false);

void sw::Window::Start()
{
    std::cout << "Creating Window..." << std::endl;

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_window = glfwCreateWindow(m_size.x, m_size.y, m_title.c_str(), nullptr, nullptr);

    if (!m_window) {
        const char* desc = nullptr;
        int code = glfwGetError(&desc);
        std::cout << "Failed to create window: " << code << " " << desc << std::endl;
        throw sw::Error("Failed to create window: " + std::to_string(code) + " " + desc);
    }
    glfwMakeContextCurrent(m_window);
    m_ready = true;
}

void sw::Window::Close()
{
    glfwDestroyWindow(m_window);
}

bool sw::Window::IsOpen()
{
    return !glfwWindowShouldClose(m_window);
}

void sw::Window::Update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void sw::Window::ToggleFullScreen()
{
    if (!m_fullScreen) {
        glfwGetWindowPos(m_window, &m_position.x, &m_position.y);
        int monitorIndex = sw::Monitor::GetCurrentMonitorIndex();
        int monitorCount = 0;
        GLFWmonitor **monitors = glfwGetMonitors(&monitorCount);
        GLFWmonitor *monitor = (monitorIndex < monitorCount) ? monitors[monitorIndex] : nullptr;

        if (!monitors)
        {
            m_fullScreen = false;
            m_flags &= ~sw::WindowFlags::FULLSCREEN_MODE;
            throw sw::Error("No monitor found!");
        } else {
            m_fullScreen = true;
            m_flags |= sw::WindowFlags::FULLSCREEN_MODE;
            glfwSetWindowMonitor(m_window, monitor, 0, 0, m_size.x, m_size.y, GLFW_DONT_CARE);
        }
    } else {
        m_fullScreen = false;
        m_flags &= ~sw::WindowFlags::FULLSCREEN_MODE;
        glfwSetWindowPos(m_window, m_position.x, m_position.y);
        glfwSetWindowMonitor(m_window, nullptr, 0, 0, m_size.x, m_size.y, GLFW_DONT_CARE);
    }
}

void sw::Window::CloseWindow()
{
    glfwSetWindowShouldClose(m_window, true);
}

void sw::Window::Maximize()
{
    if (glfwGetWindowAttrib(m_window, GLFW_RESIZABLE) == GLFW_TRUE)
    {
        glfwMaximizeWindow(m_window);
        m_flags |= sw::WindowFlags::MAXIMIZED;
    }
}

void sw::Window::Minimize()
{
    glfwIconifyWindow(m_window);
    m_flags |= sw::WindowFlags::MINIMIZED;
}

void sw::Window::Restore()
{
    if (glfwGetWindowAttrib(m_window, GLFW_RESIZABLE) == GLFW_TRUE)
    {
        glfwRestoreWindow(m_window);
    }
}

void sw::Window::SetTitle(std::string&& title)
{
    m_title = title;
    glfwSetWindowTitle(m_window, title.c_str());
}

void sw::Window::SetWindowPos(int x, int y)
{
    m_size.x = x;
    m_size.y = y;
    glfwSetWindowPos(m_window, x, y);
}

void sw::Window::SetWindowPos(sw::Vector2i pos)
{
    SetWindowPos(pos.x, pos.y);
}

void sw::Window::SetMinSize(int with, int height)
{
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowSizeLimits(m_window, with, height, mode->width, mode->height);
}

void sw::Window::SetMinSize(sw::Vector2i size)
{
    SetMinSize(size.x, size.y);
}

void sw::Window::SetMaxSize(int with, int height)
{
    m_maxSize.x = with;
    m_maxSize.y = height;
}

void sw::Window::SetMaxSize(sw::Vector2i size)
{
    SetMaxSize(size.x, size.y);
}

void sw::Window::SetSize(int with, int height)
{
    glfwSetWindowSize(m_window, with, height);
}

void sw::Window::SetSize(sw::Vector2i size)
{
    SetMinSize(size.x, size.y);
}

void sw::Window::SetVisibleCursor(bool visible)
{
    m_cursorHidden = visible;
    glfwSetInputMode(m_window, GLFW_CURSOR, (visible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN));
}

void sw::Window::SetEnableCursor(bool visible)
{
    glfwSetInputMode(m_window, GLFW_CURSOR, (visible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED));
}

void sw::Window::SetMonitor(int index)
{
    int count = 0;
    GLFWmonitor **monitors = glfwGetMonitors(&count);

    if (count > index)
        throw std::out_of_range("Monitor not found");
    const GLFWvidmode *mode = glfwGetVideoMode(monitors[index]);
    glfwSetWindowMonitor(m_window, monitors[index], 0, 0, mode->width, mode->height, mode->refreshRate);
}

void sw::Window::SetClipboardText(std::string&& text)
{
    glfwSetClipboardString(m_window, text.c_str());
}

GLFWwindow *sw::Window::GetWindow()
{
    return m_window;
}

bool sw::Window::IsFullScreen()
{
    return (m_fullScreen);
}

bool sw::Window::IsReady()
{
    return (m_ready);
}

bool sw::Window::IsCursorVisible()
{
    return (m_cursorHidden);
}

sw::Vector2i sw::Window::GetSize()
{
    return (m_size);
}

std::string sw::Window::GetTitle()
{
    return (m_title);
}

sw::Vector2i sw::Window::GetPosition()
{
    return (m_position);
}

std::string sw::Window::GetClipBoardText()
{
    return (std::string(glfwGetClipboardString(m_window)));
}
