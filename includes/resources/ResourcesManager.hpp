/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: ResourcesManager.hpp
*/

#ifndef SHIPWRECK_ENGINE_RESOURCESMANAGER_HPP
#define SHIPWRECK_ENGINE_RESOURCESMANAGER_HPP

#include <map>
#include <memory>

#include "utils/Singleton.hpp"

#include "SWEngine.hpp"
#include "Texture.hpp"
#include "ResourceMap.hpp"

namespace sw {
    class SW_MODULE_EXPORT ResourcesManager {
        public:
            /// @brief Default Constructor
            ResourcesManager();

            /// @brief
            ///
            /// \param name name of the texture
            /// \param path part to the texture's file
            void CreateTexture(std::string name, std::string path);

            /// @brief Get a Texture
            ///
            /// \param name name of the texture
            /// \return Shared pointer with the texture
            std::shared_ptr<sw::Texture>GetTexture(std::string name);
        private:
            ResourceMap<Texture> m_textures;
    };
} // SW

#endif //SHIPWRECK_ENGINE_RESOURCESMANAGER_HPP
