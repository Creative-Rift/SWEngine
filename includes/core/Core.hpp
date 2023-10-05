/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Core.hpp
*/

#ifndef SHIPWRECK_ENGINE_CORE_HPP
#define SHIPWRECK_ENGINE_CORE_HPP

#include "SWEngine.hpp"
#include "core/window/Window.hpp"

namespace sw {

    class SW_MODULE_EXPORT Core {
    public:
        static void Start();
        static void Stop();
        static void Update();
        static bool IsRunning();
    private:

    };

} // sw

#endif //SHIPWRECK_ENGINE_CORE_HPP
