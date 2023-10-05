/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Monitor.hpp
*/

#ifndef SHIPWRECK_ENGINE_MONITOR_HPP
#define SHIPWRECK_ENGINE_MONITOR_HPP

#include "GLFW/glfw3.h"
#include "utils/Vector2.hpp"

namespace sw
{
    class Monitor {
    public:
        static int GetCurrentMonitorIndex();
        static GLFWmonitor *GetMonitor(int index);
        static int GetMonitorsCount();
        static sw::Vector2i GetMonitorPos(int index);
        static std::string GetMonitorName(int index);
        static sw::Vector2i GetMonitorPhysicalSize(int index);
        static int GetMonitorFreshRate(int index);
    };
} // sw

#endif //SHIPWRECK_ENGINE_MONITOR_HPP
