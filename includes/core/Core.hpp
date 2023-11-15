/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Core.hpp
*/

#ifndef SHIPWRECK_ENGINE_CORE_HPP
#define SHIPWRECK_ENGINE_CORE_HPP

#include "SWEngine.hpp"
#include "core/window/Window.hpp"
#include "scene/sceneManager/SceneManager.hpp"
#include "resources/ResourcesManager.hpp"
#include "utils/Chrono.hpp"

namespace sw {

    class SW_MODULE_EXPORT Core {
        public:
            static Chronos m_chronos;

            /// @brief Start the Engine, call it before any other action
            static void Start();

            /// @brief Stop the Engine, call it at the end of your program
            static void Stop();

            /// @brief Call all update for one frame
            static void Update();

            /// @brief Check if the window is open
            static bool IsRunning();

            /// @brief Get SceneManager
            ///
            /// \return sw::SceneManager&
            [[nodiscard]] static sw::SceneManager &GetSceneManager();

            /// @brief Get ResourcesManager
            ///
            /// \return sw::SceneManager&
            [[nodiscard]] static sw::ResourcesManager &GetResourceManager();

            static void setFrameRateLimit(unsigned int frameRate);

        private:
            static SceneManager m_sceneManager;
            static ResourcesManager m_resourceManager;
            static Chronos m_chronosWindow;
            static double m_frameRate;
    };

} // sw

#endif //SHIPWRECK_ENGINE_CORE_HPP
