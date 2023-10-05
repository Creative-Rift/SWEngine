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
        /// @brief Get the index of the current monitor where the window is displayed
        ///
        /// \return int
        static int GetCurrentMonitorIndex();

        /// @brief Get a monitor by it's index
        ///
        /// \param index
        /// \return GLFWmonitor *
        static GLFWmonitor *GetMonitor(int index);

        /// @brief Get the number of monitor connected
        ///
        /// \return int
        static int GetMonitorsCount();

        /// @brief Get the position of the monitor (current video mode used)
        ///
        /// \param index
        /// \return sw:Vector2i(x, y)
        static sw::Vector2i GetMonitorPos(int index);

        /// @brief Get the size of the monitor (current video mode used)
        ///
        /// \param index
        /// \return sw::Vector2i(width, height)
        static sw::Vector2i GetMonitorSize(int index);

        /// @brief Get the name of a Monitor
        ///
        /// \param index
        /// \return std::string
        static std::string GetMonitorName(int index);

        /// @brief Get the physical size of a monitor
        ///
        /// \param index
        /// \return sw::Vector2i(width, height)
        static sw::Vector2i GetMonitorPhysicalSize(int index);

        /// @brief Get fresh rate of a monitor
        ///
        /// \param index
        /// \return int
        static int GetMonitorFreshRate(int index);
    };
} // sw

#endif //SHIPWRECK_ENGINE_MONITOR_HPP
