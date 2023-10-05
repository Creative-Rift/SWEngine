/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: SWEngine.hpp
*/

#ifndef SHIPWRECK_ENGINE_SWENGINE_HPP
#define SHIPWRECK_ENGINE_SWENGINE_HPP

#if defined(_WIN32)
    #define SW_MODULE_WINDOWS_SYSTEM
#elif defined(__unix__)
    #if defined(__linux__)
        #define SW_MODULE_LINUX_SYSTEM
    #else
        #error Unsupported UNIX system
    #endif

#else

    #error Unsupported system
#endif

#if defined(SW_MODULE_WINDOWS_SYSTEM)
    #define SW_MODULE_EXPORT __declspec(dllexport)
    #define SW_MODULE_IMPORT __declspec(dllimport)
#else
    #define SW_MODULE_EXPORT
    #define SW_MODULE_IMPORT
#endif

#endif //SHIPWRECK_ENGINE_SWENGINE_HPP
