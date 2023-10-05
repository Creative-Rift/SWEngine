/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Monitor.cpp
*/

#include "core/monitor/Monitor.hpp"
#include "core/window/Window.hpp"

int sw::Monitor::GetCurrentMonitorIndex()
{
    int monitorCount;
    GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
    GLFWmonitor* monitor = nullptr;

    if (monitorCount == 1)
        return 0;
    if (sw::Window::IsFullScreen()) {
        monitor = glfwGetWindowMonitor(sw::Window::GetWindow());
        for (int i = 0; i < monitorCount; i++)
            if (monitors[i] == monitor)
                return i;
        return 0;
    } else {
        int winX = 0;
        int winY = 0;

        glfwGetWindowPos(sw::Window::GetWindow(), &winX, &winY);
        for (int i = 0; i < monitorCount; i++)
        {
            int mx = 0;
            int my = 0;
            int width = 0;
            int height = 0;

            monitor = monitors[i];
            glfwGetMonitorWorkarea(monitor, &mx, &my, &width, &height);
            if (winX >= mx && winX <= (mx + width) && winY >= my && winY <= (my + height))
                return i;
        }
    }
    return (0);
}

GLFWmonitor *sw::Monitor::GetMonitor(int index)
{
    int count = 0;
    GLFWmonitor **monitors = glfwGetMonitors(&count);

    if (index > count)
        throw std::out_of_range("Monitor index doesn't exist");
    return (monitors[index]);
}

int sw::Monitor::GetMonitorsCount()
{
    int count = 0;
    glfwGetMonitors(&count);

    return (count);
}

sw::Vector2i sw::Monitor::GetMonitorPos(int index)
{
    int height;
    int width;

    glfwGetMonitorPos(GetMonitor(index), &width, &height);
    return (sw::Vector2i(width, height));
}

std::string sw::Monitor::GetMonitorName(int index)
{
    return (std::string(glfwGetMonitorName(GetMonitor(index))));
}

sw::Vector2i sw::Monitor::GetMonitorPhysicalSize(int index)
{
    int height;
    int width;

    glfwGetMonitorPhysicalSize(GetMonitor(index), &width, &height);
    return (sw::Vector2i(width, height));
}

int sw::Monitor::GetMonitorFreshRate(int index)
{
    const GLFWvidmode *videoMode = glfwGetVideoMode(GetMonitor(index));

    return (videoMode->refreshRate);
}
