/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: GameObject.hpp
*/

#ifndef SHIPWRECK_ENGINE_GAMEOBJECT_HPP
#define SHIPWRECK_ENGINE_GAMEOBJECT_HPP

#include <string>

#include "boost/uuid/uuid.hpp"
#include "scene/Scene.hpp"
#include "managers/base/AManager.hpp"

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

            /// @brief Create new Component.
            ///
            /// \tparam Cpt Component type
            /// @param args The arguments for the Component constructor.
            /// @return Cpt&
            template <ClassComponent Cpt, typename... Args>
            Cpt& createComponent(Args... values);

            /// @brief Get a Component.
            ///
            /// \tparam Cpt Component type
            /// @return Cpt&
            template <ClassComponent Cpt>
            Cpt& getComponent();

            /// @brief Check if the GameObject has a Component
            ///
            /// \tparam Cpt Component type
            /// @return boolean
            template <ClassComponent Cpt>
            [[nodiscard]] bool hasComponent() const;

            /// @brief Delete a Component.
            ///
            /// \tparam Cpt Component type
            template <ClassComponent Cpt>
            void deleteComponent();

            /// @brief Define the order
            ///
            /// \tparam Cpt Component type
            /// \param layer int
            template <ClassComponent Cpt>
            void setLayer(int layer);

        private:
            boost::uuids::uuid m_id;
            std::string m_name;
            bool m_isActive;
            Scene &m_scene;
    };

#include "GameObject.inl"

} // sw

#endif //SHIPWRECK_ENGINE_GAMEOBJECT_HPP
