/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: IGameObject.hpp
*/

#ifndef SHIPWRECK_ENGINE_IGAMEOBJECT_HPP
#define SHIPWRECK_ENGINE_IGAMEOBJECT_HPP

#include <string>

namespace sw {

    class Scene;

    class IGameObject {
        public:
            /// @brief Default Destructor
            virtual ~IGameObject() = default;

            /// @brief Get IGameObject's name
            ///
            /// @return std::string
            [[nodiscard]] virtual std::string name() const = 0;

            /// @brief Return a reference of the Scene attached to the IGameObject.
            ///
            /// @return sw::Scene&
            virtual Scene &scene() = 0;

            /// @brief Return the id.
            ///
            /// @return boost::uuids::uuid
            [[nodiscard]] virtual boost::uuids::uuid id() const = 0;

            /// @brief Check if the IGameObject is active or not.
            ///
            /// @return boolean
            [[nodiscard]] virtual bool isActive() const = 0;

            /// @brief Define if the IGameObject is active.
            ///
            /// @param value boolean
            virtual void setActive(bool value) = 0;
    };
} // sw

#endif //SHIPWRECK_ENGINE_IGAMEOBJECT_HPP
