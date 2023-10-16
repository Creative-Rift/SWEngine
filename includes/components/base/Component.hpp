/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Component.hpp
*/


#ifndef SHIPWRECK_ENGINE_COMPONENT_HPP
#define SHIPWRECK_ENGINE_COMPONENT_HPP

#include <string>


namespace sw {

    class GameObject;

    class Component {
        public:
            /// @brief Default Constructor.
            ///
            /// @param sw::GameObject& - GameObject attached to the new component
            explicit Component(GameObject &gameObject, bool isActive = true);

            /// @brief Default Destructor.
            virtual ~Component() = default;

            /// @brief Return the name of the GameObject attached to the Component.
            ///
            /// @return std::string
            [[nodiscard]] std::string gameObjectName() const;

            /// @brief Set if the component is active.
            ///
            /// @param value boolean
            void setActive(bool value);

            /// @brief Check if the Component is active.
            ///
            /// @return boolean
            [[nodiscard]] bool isActive() const;

            /// @brief Return the GameObject attached to the Component.
            ///
            /// @return sw::GameObject&
            [[nodiscard]] GameObject &gameObject() const;

        protected:
            bool m_isActive;
            GameObject &m_gameObject;

            Component() = delete;
            Component(Component const&) = delete;
            Component(Component &&) = delete;
            Component &operator=(Component const &) = delete;
            Component &operator=(Component &&) = delete;
    };
} // SW
#endif //SHIPWRECK_ENGINE_COMPONENT_HPP
