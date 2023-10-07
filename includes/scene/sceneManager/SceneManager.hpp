/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: SceneManager.hpp
*/

#ifndef SHIPWRECK_ENGINE_SCENEMANAGER_HPP
#define SHIPWRECK_ENGINE_SCENEMANAGER_HPP

#include <map>
#include <string>
#include <memory>

#include "SWEngine.hpp"
#include "scene/Scene.hpp"

namespace sw
{
    class SW_MODULE_EXPORT SceneManager
    {
    public:
        /// @brief Default constructor
        SceneManager() noexcept;

        /// @brief Create a Scene
        ///
        /// \param name
        /// \return Safe pointer to the new scene
        std::shared_ptr<Scene> createScene(std::string name);

        /// @brief Create a Scene by giving a custom class based on sw::Scene
        ///
        /// \param name
        /// \return Safe pointer to the new scene
        std::shared_ptr<Scene> createScene(Scene* scene);

        /// @brief Load a scene, the scene will be load at the start of the next frame
        ///
        /// \param sceneName
        void loadScene(std::string sceneName);

        /// @brief Unload all scene
        /// @warning called by the core dont call it
        void unloadAllScene();

        /// @brief Check if a new scene will be load
        /// @warning called by the core dont call it
        void checkForNewScene();

        /// @brief Get a Scene by it's name
        ///
        /// \param sceneName
        /// \return Safe pointer to the scene
        [[nodiscard]]std::shared_ptr<Scene> getSceneByName(std::string sceneName);

        /// @brief Get a Scene by it's name. First added = index 0
        ///
        /// \param index
        /// \return Safe pointer to the scene
        [[nodiscard]]std::shared_ptr<Scene> getSceneByIndex(unsigned int index);

        /// @brief Get the current active Scene
        ///
        /// \return Safe pointer to the scene
        [[nodiscard]]std::shared_ptr<Scene> getActiveScene();

    private:
        std::map<std::string, std::shared_ptr<Scene>> m_scenes;
        std::string m_activeScene;
        std::string m_nextActiveScene;
    };
} // SW

#endif //SHIPWRECK_ENGINE_SCENEMANAGER_HPP
