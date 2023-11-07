/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: AManager.hpp
*/

#ifndef SHIPWRECK_ENGINE_AMANAGER_HPP
#define SHIPWRECK_ENGINE_AMANAGER_HPP

#include <string>
#include <memory>
#include <forward_list>
#include <map>
#include <set>

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/random_generator.hpp"

#include "managers/base/IManager.hpp"
#include "Concept.hpp"
#include "scene/Scene.hpp"
#include "components/base/Component.hpp"

namespace sw {

    class GameObject;

    template<ClassComponent Cpt>
    class AManager : public IManager {
        public:
            AManager() = delete;

            /// @brief Default Constructor.
            ///
            /// @param managerName std::string - Manager's name.
            /// @param sceneRef sw::Scene - Scene attached to the Manager.
            AManager(const std::string &name, Scene &scene);

            /// @brief Default Destructor.
            virtual ~AManager();

            /// @brief Get the name of the Manager.
            ///
            /// @return std::string
            [[nodiscard]] std::string name() const;

            /// @brief Get the Scene attached to the Manager.
            ///
            /// @return sw::Scene&
            [[nodiscard]] Scene &scene() const;

            /// @brief Check if the Manager is active.
            ///
            /// @return boolean
            [[nodiscard]] bool isActive() const;

            /// @brief Define id the Manage is active.
            ///
            /// @param value boolean
            void setActive(bool value);

            /// @brief Check if the Manager is loaded.
            ///
            /// @return boolean - True if loaded, false otherwise
            [[nodiscard]] virtual bool isLoad() const;

            /// @brief Load the Manager.
            virtual void load();

            /// @brief Update all component of the Manager.
            virtual void update();

            /// @brief Unload the Manager.
            virtual void unload();

            /// @brief Create a Component for a GameObject.
            ///
            /// @param gameObjectName
            /// @param args Arguments for the Component constructor.
            /// @return sw::Cpt
            template <typename... Args>
            Cpt& createComponent(const boost::uuids::uuid& uuid, Args... values);

            /// @brief Verify of the Component exist.
            ///
            /// @param gameObjectName GameObject's name.
            /// @return boolean
            // [[nodiscard]] virtual bool hasComponent(const std::string &gameObjectName) const;

            /// @brief Verify of the Component exist.
            ///
            /// @param gameObjectId GameObject's id.
            /// @return boolean
            [[nodiscard]] virtual bool hasComponent(const boost::uuids::uuid &gameObjectId) const;

            /// @brief Delete the Component attached to an GameObject.
            ///
            /// @param gameObjectName GameObject's name.
            // virtual void deleteComponent(const std::string &gameObjectName);

            /// @brief Delete the Component attached to an GameObject.
            ///
            /// @param gameObjectId GameObject's id.
            virtual void deleteComponent(const boost::uuids::uuid &gameObjectId);

            /// @brief Delete all the existing Components.
            virtual void eraseComponents();

            /// @brief Set the layer of the Component.
            ///
            /// @param gameObjectName GameObject's name.
            // virtual void setLayer(const std::string &gameObjectName, int layer);

            /// @brief Set the layer of the Component.
            ///
            /// @param gameObjectId GameObject's name.
            virtual void setLayer(const boost::uuids::uuid &gameObjectId, int layer);

            /// @brief Get the @b Component layer associate with the @b GameObject
            /// corresponding to the given name.
            ///
            /// @param gameObjectName The @b GameObject name.
            /// @return The layer of the wanted @b Component.
            // [[nodiscard]] virtual int getLayer(const std::string &gameObjectName) const;

            /// @brief Get the @b Component layer associate with the @b GameObject
            /// corresponding to the given name.
            ///
            /// @param gameObjectId GameObject's id.
            /// @return The layer of the wanted @b Component.
            [[nodiscard]] virtual int getLayer(const boost::uuids::uuid &gameObjectId) const;

            /// @brief Get a Component/
            ///
            /// @param gameObjectName
            /// @return sw::Cpt&
            // Cpt& getComponent(const std::string& gameObjectName);

        protected:
            std::string m_name;
            Scene &m_scene;
            bool m_isLoad;
            bool m_isActive;

            class ComponentMap : public std::map<boost::uuids::uuid, std::shared_ptr<Cpt>> {
                public:
                    friend AManager;
            }
            /// @brief Store all Components.
            ///
            /// @c Cpt define the type of the component (Sprite, Transform, ...).
            ///
            /// @arg boost::uuids::uuid - GameObject's id.
            /// @arg std::shared_ptr<GameObject>
            m_components;

            class ComponentsLayers : private std::forward_list<std::pair<int, boost::uuids::uuid>>
            {
                public:
                    using std::forward_list<std::pair<int, boost::uuids::uuid>>::begin;
                    using std::forward_list<std::pair<int, boost::uuids::uuid>>::end;

                friend AManager;
            }
            /// @brief The map use to reference the Components by their layers.
            ///
            /// @arg int                Component layer.
            /// @arg boost::uuids::uuid Component id.
            m_componentsLayers;

            /// @brief This set has all component that will be deleted
            /// at the end of the frame's computation
            std::set<boost::uuids::uuid> m_deleteComponent;

            /// @brief Function called to customize the behavior of your components.
            virtual void onUpdate() = 0;

            /// @brief Delete all Components from m_deleteComponent.
            /// This function is called during the update process
            void deleteRequestedComponents();

    }; // class AManager

#include "managers/base/AManager.inl"

} // sw

#endif //SHIPWRECK_ENGINE_AMANAGER_HPP
