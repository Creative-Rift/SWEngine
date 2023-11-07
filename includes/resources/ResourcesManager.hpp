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
            ResourcesManager();

            void CreateTexture(std::string name, std::string path);
            std::shared_ptr<sw::Texture>GetTexture(std::string name);
        private:
            ResourceMap<Texture> m_textures;
    };
} // SW

#endif //SHIPWRECK_ENGINE_RESOURCESMANAGER_HPP
