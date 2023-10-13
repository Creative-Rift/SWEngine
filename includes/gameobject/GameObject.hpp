/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: GameObject.hpp
*/

#ifndef SHIPWRECK_ENGINE_GAMEOBJECT_HPP
#define SHIPWRECK_ENGINE_GAMEOBJECT_HPP

#include <string>

#include "boost/uuid/uuid.hpp"
#include "scene/Scene.hpp"

namespace sw {

    class GameObject {
        public:
            GameObject() = delete;

            /// @brief Default Constructor
            ///
            /// @param name Name of the game object.
            /// @param scene Scene where the GameObject will be created.
            /// @param isActive Define if the GameObject is active
            GameObject(const std::string name, Scene &scene, bool isActive = true);

            /// @brief Default Destructor of an GameObject.
            ~GameObject() = default;

            /// @brief Return the name of the GameObject.
            ///
            /// @return std::string
            [[nodiscard]] std::string name() const;

            /// @brief Return a reference of the Scene attached to the Entity.
            ///
            /// @return sw::Scene&
            [[nodiscard]] Scene &scene();

            /// @brief Return the id.
            ///
            /// @return boost::uuids::uuid
            [[nodiscard]] boost::uuids::uuid id() const;

            /// @brief Check if the GameObject is active or not.
            ///
            /// @return boolean
            [[nodiscard]] bool isActive() const;

            /// @brief Define if the GameObject is active.
            ///
            /// @param value boolean
            void setActive(bool active);

        private:
            boost::uuids::uuid m_id;
            std::string m_name;
            bool m_isActive;
            Scene &m_scene;
    };

} // sw

#endif //SHIPWRECK_ENGINE_GAMEOBJECT_HPP
