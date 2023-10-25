/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: IManager.hpp
*/

#ifndef SHIPWRECK_ENGINE_IMANAGER_HPP
#define SHIPWRECK_ENGINE_IMANAGER_HPP

#include "boost/uuid/uuid.hpp"
#include "utils/exception/Error.hpp"

namespace sw {

    class Scene;

    class IManager {
        public:
            /// @brief Default Destructor .
            virtual ~IManager() = default;

            /// @brief Get the name of the Manager.
            ///
            /// @return std::string
            [[nodiscard]] virtual std::string name() const = 0;

            /// @brief Get the Scene attached to the Manager.
            ///
            /// @return sw::Scene&
            [[nodiscard]] virtual Scene &scene() const = 0;

            /// @brief Check if the Manager is active.
            ///
            /// @return boolean
            [[nodiscard]] virtual bool isActive() const = 0;

            /// @brief Define id the Manage is active.
            ///
            /// @param value boolean
            virtual void setActive(bool value) = 0;

            /// @brief Check if the Manager is loaded.
            ///
            /// @return boolean - True if loaded, false otherwise
            [[nodiscard]] virtual bool isLoad() const = 0;

            /// @brief Load the Manager.
            virtual void load() = 0;

            /// @brief Update all component of the Manager.
            virtual void update() = 0;

            /// @brief Unload the Manager.
            virtual void unload() = 0;

            /// @brief Verify of the Component exist.
            ///
            /// @param gameObjectName GameObject's name.
            /// @return boolean
            // [[nodiscard]] virtual bool hasComponent(const std::string &gameObjectName) const = 0;

            /// @brief Verify of the Component exist.
            ///
            /// @param gameObjectId GameObject's id.
            /// @return boolean
            [[nodiscard]] virtual bool hasComponent(const boost::uuids::uuid &gameObjectId) const = 0;

            /// @brief Delete the Component attached to an GameObject.
            ///
            /// @param gameObjectName GameObject's name.
            // virtual void deleteComponent(const std::string &gameObjectName) = 0;

            /// @brief Delete the Component attached to an GameObject.
            ///
            /// @param gameObjectId GameObject's id.
            virtual void deleteComponent(const boost::uuids::uuid &gameObjectId) = 0;

            /// @brief Delete all the existing Components.
            virtual void eraseComponents() = 0;

            /// @brief Set the layer of the Component.
            ///
            /// @param gameObjectName GameObject's name.
            // virtual void setLayer(const std::string &gameObjectName, int layer) = 0;

            /// @brief Set the layer of the Component.
            ///
            /// @param gameObjectId GameObject's name.
            virtual void setLayer(const boost::uuids::uuid &gameObjectId, int layer) = 0;

            /// @brief Get the @b Component layer associate with the @b GameObject
            /// corresponding to the given name.
            ///
            /// @param gameObjectName The @b GameObject name.
            /// @return The layer of the wanted @b Component.
            // [[nodiscard]] virtual int getLayer(const std::string &gameObjectName) const = 0;

            /// @brief Get the @b Component layer associate with the @b GameObject
            /// corresponding to the given name.
            ///
            /// @param gameObjectId GameObject's id.
            /// @return The layer of the wanted @b Component.
            [[nodiscard]] virtual int getLayer(const boost::uuids::uuid &gameObjectId) const = 0;

    }; // class IManager

} // sw

#endif //SHIPWRECK_ENGINE_IMANAGER_HPP
