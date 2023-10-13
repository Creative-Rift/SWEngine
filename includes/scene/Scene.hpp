/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Scene.hpp
*/

#ifndef SHIPWRECK_ENGINE_SCENE_HPP
#define SHIPWRECK_ENGINE_SCENE_HPP

#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <memory>

#include "boost/uuid/uuid.hpp"

#include "SWEngine.hpp"
#include "managers/base/IManager.hpp"

namespace sw {

    class GameObject;

    class SW_MODULE_EXPORT Scene {
        public:

            /// @brief Deleted default constructor
            Scene() = delete;

            /// @brief Deleted copy constructor
            Scene(Scene &scene) = delete;

            /// @brief Deleted copy constructor
            Scene(Scene &&scene) = delete;

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
            [[nodiscard]] const std::string &getName() const;

            /// @brief Check if the scene is loaded
            ///
            /// \return boolean
            [[nodiscard]] bool isLoad() const;

            /// @brief Create GameObject.
            ///
            /// @param gameObjectName
            /// @return sw::GameObject&
            GameObject &createGameObject(const std::string &gameObjectName);

            /// @brief Get the GameObject corresponding to the given name.
            ///
            /// @param gameObjectName std::string
            ///
            /// @return sw::GameObject&.
            [[nodiscard]] GameObject &getGameObjectByName(const std::string &gameObjectName);

            /// @brief Get the GameObject corresponding to the given id.
            ///
            /// @param gameObjectId boost::uuids::uuid
            ///
            /// @return sw::GameObject&.
            [[nodiscard]] GameObject &getGameObjectById(const boost::uuids::uuid gameObjectId);

            /// @brief Check if the GameObject exist.
            ///
            /// @param gameObjectName std::string
            ///
            /// @return boolean
            [[nodiscard]] bool hasGameObject(const std::string &gameObjectName);

            /// @brief Check if the GameObject exist.
            ///
            /// @param gameObjectId boost::uuids::uuid
            ///
            /// @return boolean
            [[nodiscard]] bool hasGameObject(const boost::uuids::uuid gameObjectId);

            /// @brief Delete GameObject.
            ///
            /// @param gameObjectName std::string
            void deleteGameObject(const std::string &gameObjectName);

            /// @brief Delete GameObject.
            ///
            /// @param gameObjectId boost::uuids::uuid
            void deleteGameObject(const boost::uuids::uuid gameObjectId);

            /// @brief Delete all GameObject.
            void eraseGameObject();


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

            /// @brief This set has all GameObject that will be deleted
            /// at the end of the frame's computation
            std::unordered_set<boost::uuids::uuid> m_deleteGameObject;

            class GameObjectMap : private std::unordered_map<boost::uuids::uuid, std::shared_ptr<GameObject>> {
                public:
                    using std::unordered_map<boost::uuids::uuid, std::shared_ptr<GameObject>>::begin;
                    using std::unordered_map<boost::uuids::uuid, std::shared_ptr<GameObject>>::end;
                    using std::unordered_map<boost::uuids::uuid, std::shared_ptr<GameObject>>::operator[];

                    friend Scene;
            }
            /// @brief Store all GameObject.
            ///
            /// @arg boost::uuids::uuid - GameObject's id.
            /// @arg std::shared_ptr<GameObject>
            m_gameObjects;

            /// @brief Delete all GameObject from m_deleteGameObject
            void deleteRequestedGameObject();

            /// @brief This set has all managers that will be deleted
            /// at the end of the frame's computation
            std::unordered_set<std::string> m_managersToDelete;

            class ManagerMap : private std::unordered_map<std::string, std::shared_ptr<IManager>> {
                public:
                    using std::unordered_map<std::string, std::shared_ptr<IManager>>::begin;
                    using std::unordered_map<std::string, std::shared_ptr<IManager>>::end;
                    using std::unordered_map<std::string, std::shared_ptr<IManager>>::operator[];

                    friend Scene;
            }
            /// @brief Store all Managers.
            ///
            /// @arg std::string          The Manager name.
            /// @arg std::shared_ptr<Cpt> The Manager itself.
            m_managers;
    };

} // sw

#endif //SHIPWRECK_ENGINE_SCENE_HPP
