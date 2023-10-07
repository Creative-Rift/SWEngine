/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Scene.hpp
*/

#ifndef SHIPWRECK_ENGINE_SCENE_HPP
#define SHIPWRECK_ENGINE_SCENE_HPP

#include <string>

#include "SWEngine.hpp"

namespace sw {

    class SW_MODULE_EXPORT Scene
    {
    public:

        /// @brief Deleted default constructor
        Scene() = delete;

        /// @brief Deleted copy constructor
        Scene(Scene& scene) = delete;

        /// @brief Deleted copy constructor
        Scene(Scene&& scene) = delete;

        /// @brief Scene's Constructor
        ///
        /// \param name
        explicit Scene(std::string name);

        /// @brief Default destructor
        ~Scene() = default;

        /// @brief Load a scene, it create add element needed to work
        /// @warning Function used bt the core, don't call it
        virtual void load();

        /// @brief Update a scene, it update all element needed to work
        /// @warning Function used bt the core, don't call it
        virtual void update();

        /// @brief Load a scene, it create add element needed to work
        /// @warning Function used bt the core, don't call it
        virtual void unload();

        /// @brief Get the name of the scene
        ///
        /// \return std::string
        [[nodiscard]] const std::string& getName() const;

        /// @brief Check if the scene is loaded
        ///
        /// \return boolean
        [[nodiscard]] bool isLoad() const;

    protected:
        /// @brief Name of the scene
        std::string m_name;

        /// @brief Check is the scene is loaded
        bool m_isLoad;

        /// @brief Update all physical related stuff (Collision, RigidBody, ...)
        void updatePhysic();

        /// @brief Update all logic related stuff (your script, input, ...)
        void updateLogic();

        /// @brief Update all graphical related stuff (Sprite, text, Model, ...)
        void updateGraphics();
    };

} // sw

#endif //SHIPWRECK_ENGINE_SCENE_HPP
